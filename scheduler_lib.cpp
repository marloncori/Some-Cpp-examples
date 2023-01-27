--Scheduler.h----------------------------------------------------
#pragma once
 
#include <map>
#include <functional>
#include <chrono>
#include <mutex>
#include <thread>
#include <condition_variable>
#include <memory>
 
//http://www.sgi.com/tech/stl/Multimap.html
 
typedef std::map<std::chrono::system_clock::time_point, std::function<void()>>::iterator task_it;
//Single threaded scheduler
class Scheduler {
private:
    std::multimap<std::chrono::system_clock::time_point, std::function<void()>> tasks;
    std::mutex mutex;
    std::unique_ptr<std::thread> thread;
    std::condition_variable blocker;
    bool go_on;
 
public:
    //Scheduler& operator=(const Scheduler& rhs) = delete;
    //Scheduler(const Scheduler& rhs) = delete;
 
    Scheduler();
    ~Scheduler();
 
    void ThreadLoop();
    task_it ScheduleAt(const std::chrono::system_clock::time_point & time, std::function<void()> func);
    void ScheduleEvery(std::chrono::system_clock::duration interval, std::function<void()> func);
    void unschedule(const task_it& handle);
};
 
--Scheduler.cpp----------------------------------------------------
 
#include "Scheduler.h"
 
 
Scheduler::Scheduler() : go_on(true) {
    thread.reset(new std::thread([this](){ this->ThreadLoop(); }));
}
 
Scheduler::~Scheduler() {
    go_on = false;
    ScheduleAt(std::chrono::system_clock::now(), [](){});
    thread->join();
}
 
void Scheduler::ThreadLoop() {
    while(go_on) {
        //Pop next scheduled task
        std::function<void()> todo;
        {
            
            std::unique_lock<std::mutex> lock(mutex);
            auto now = std::chrono::system_clock::now();
                        
            if (tasks.empty()==false){
                printf("sheduler awoken. Now: %u. First task at: %u. condition %d\n", std::chrono::system_clock::to_time_t(now), std::chrono::system_clock::to_time_t(tasks.begin()->first), tasks.begin()->first <= now);
            }
            //added a 5 second hack because this keeps waking up 1 sec before it should
            if ( tasks.empty()==false && tasks.begin()->first <= (now + std::chrono::seconds(5)))
            {
                todo = tasks.begin()->second;
                tasks.erase(tasks.begin());
            }
        }
        
        // Run tasks while unlocked so tasks can schedule new tasks
        if (todo){
            printf("!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!executing task!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!\n");
            todo();
        }
 
        //Block until next scheduled task
        {
            std::unique_lock<std::mutex> lock(mutex);
            if (tasks.empty())
                blocker.wait(lock);
            else
                blocker.wait_until(lock, tasks.begin()->first);
        }
    }
}
 
task_it Scheduler::ScheduleAt(const std::chrono::system_clock::time_point & time, std::function<void()> func) {
    std::unique_lock<std::mutex> lock(mutex);
 
    auto it = tasks.insert(std::make_pair(time, func));
    if (it == tasks.begin())
        blocker.notify_one();
 
    return it;  //Multimap has the important property that inserting a new element into a multimap does not invalidate iterators that point to existing elements. Erasing an element from a multimap also does not invalidate any iterators, except, of course, for iterators that actually point to the element that is being erased.    
}
 
void Scheduler::ScheduleEvery(std::chrono::system_clock::duration interval, std::function<void()> func){
    std::function<void()> waitFunc = [this,interval,func](){
        func();
        this->ScheduleEvery(interval, func);
    };
    ScheduleAt(std::chrono::system_clock::now() + interval, waitFunc);
}
 
void Scheduler::unschedule(const task_it& handle){
    std::unique_lock<std::mutex> lock(mutex);
    auto fresh_it = std::find(tasks.begin(), tasks.end(), *handle); //i get a fresh iterator to be on the safe side
    if (fresh_it != tasks.end()){
        tasks.erase(fresh_it);
        blocker.notify_one(); //not sure this is nessessary but to be on the safe side
    }
}