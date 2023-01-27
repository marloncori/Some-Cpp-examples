#include<iostream>
#include<ostream>
#include<memory>

class Time {
    private:
        int hour;
        int minute;
        int second;

    public: 
        Time();
        void setTime();
        void show();
        Time operator+(Time t1);
        friend std::ostream& operator<<(std::ostream &out, Time &tm);   
};

Time::Time() {
   hour=0, minute=0; second=0;
}

void Time::show(){
    std::cout<< " This is the current time: \n\t" << hour
        << ":" << minute << ":" << second << std::endl;

}

//overloading ‘+’ operator   
Time Time::operator+(Time other)    //operator function
{
    Time thisOne;
    int a, b;
    a = second + other.second;
    thisOne.second = a % 60;
    b = (a/60) + minute + other.minute;
    thisOne.minute = b % 60;
    thisOne.hour = (b/60) + hour + other.hour;
    thisOne.hour = thisOne.hour % 12;
    return thisOne;
}

void Time::setTime() {
    system("color 4e");
    std::cout << "\n******************************" << std::endl;
    std::cout << " **  CONSOLE CLOCK SETTING ** "<< std::endl;
    std::cout << "******************************" << std::endl;
    std::cout << "\n\t Enter the hour (0-11): ";
    std::cin >> hour;
    std::cout << "\n Nowq enter the minutes (0-59): ";
    std::cin >> minute;
    std::cout << "\n Finally enter the seconds (0-59): ";
    std::cin >> second;
}

// overloading ‘<<‘ operator

// define the overloaded function

std::ostream& operator<<(std::ostream& out, Time& tm) {
    out << "Time is: \n\t" << tm.hour << " hours : " << tm.minute << " min : " << tm.second << " seconds.";
 return out;
}

int main(){

    std::unique_ptr<Time> t1 = std::make_unique<Time>(Time());
    std::unique_ptr<Time> t2 = std::make_unique<Time>(Time());
    std::unique_ptr<Time> t3 = std::make_unique<Time>(Time());

    std::cout << "\n Enter the first time " << std::endl;
            t1->setTime();

    std::cout << "\n Enter the second time " << std::endl;
            t2->setTime();

        *t3 = *t1 + *t2;    
        //adding of two time object using ‘+’ operator

    std::cout << "\n First time you set: ";
            std::cout << *t1;

    std::cout << "\n Second time you set: ";
            std::cout << *t2;

    std::cout << "\n Sum of times: ";
            std::cout << *t3;

  std::cin.get();
  
  return 0;
}