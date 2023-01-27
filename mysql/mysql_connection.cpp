#include <mysql.h>
#include <mysqld_error.h>

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <stdexcept>

#define HOST      "localhost"
#define USER      "marlon_cpp"
#define PASSWORD  "Mc0489921%"
#define DATABASE  "school"
#define PORT       3306

struct Student {
   int collegeId;
   std::string name;
   std::string birthday;
   float grade;
};

struct App {
   bool isRunning;
   int answer;
};

struct Database {
   char* consult;
   char* sentence;
   std::string sentenceAux;
};

Student getUserInput(Student& student){
    std::cout << " Colleged ID: ";
    std::cin >> student.collegeId;            
    std::cin.ignore(100, '\n');

    std::cout << " Name:";
    std::getline(std::cin, student.name);
     //std::cin does not read spaces
    std::cout << " Birthday: ";
    std::getline(std::cin, student.birthday);

    std::cout << " Grade: ";
    std::cin >> student.grade;
    std::cin.ignore(100, '\n');
    std::cout << std::endl;

  return student;
}

Database setUpdateInfo(Database& db, Student& student){
    db.sentenceAux = "INSERT INTO student(College_ID, Name, Birthday, Grade) VALUES('%d', '%s', '%s', '%f')";
    db.sentence = new char[db.sentenceAux.length() + 1];

    //copy string statement into a *char
    strcpy(db.sentence, db.sentenceAux.c_str());
                                                //college_id
    db.consult = new char[strlen(db.sentence) + sizeof(int)   //grade 
                           + student.name.size() + student.birthday.size() + sizeof(float)];
    //replace the %d %i %s %f with actual values
    sprintf(db.consult, db.sentence,  student.collegeId, 
           student.name.c_str(), student.birthday.c_str(), student.grade);
  return db;
}

int main(){
    Student student;
    Database db;

    App app;
        app.isRunning = true;
    MYSQL* driver;

    try{
        if(!(driver = mysql_init(0))){

            std::cerr << "\n ERROR: MySql Object could not be created. \n So connection with database has not been stablished!" <<std::endl;
        }
        else {
            if(!mysql_real_connect(driver, HOST, USER, PASSWORD, DATABASE, PORT, NULL, 0)){
               std::cerr << "\n ERROR: Some database info is wrong \n or the requested database does not exist." << std::endl;
               std::cout << mysql_error(driver) <<std::endl;
            }
            else {
                std::cout << " Connection to database successful! \n Logged in." << std::endl;

                while(app.isRunning){
                    student = getUserInput(student);
                    db = setUpdateInfo(db, student);

                    //make attempt
                    if(mysql_ping(driver)){
                        std::cerr << "\n ERROR: Impossibe to connect to database..." << std::endl;
                        std::cout << mysql_error(driver) << std::endl;
                    }
                    if(mysql_query(driver, db.consult)){
                        std::cerr << "\n ERROR: " << mysql_error(driver) << std::endl;
                        rewind(stdin);
                        getchar();
                    }
                    else {
                        std::cout << " Entry successuflly updated!" << std::endl;
                    }
                    mysql_store_result(driver);
                    std::cout << std::endl << " Do you want to update another entry?" << std::endl;
                    std::cout << "\t [1] : yes" << std::endl;
                    std::cout << "\t [0] : no" << std::endl;
                    std::cout << "  --> answer: ";
                    std::cin >> app.answer;
                    std::cin.ignore(100, '\n');
 
                    if(!app.answer){
                        app.isRunning = false;
                    }
                    std::cout << std::endl;                   
                }
            }
        }
    } 
    catch(const std::runtime_error &err){
        std::cerr << "\t An error unexpected has happened: " << err.what() << std::endl;
    }

    std::cout << "\n\n :::: END OF PROGRAM ::::" <<std::endl;

    mysql_close(driver);
    return 0;
}