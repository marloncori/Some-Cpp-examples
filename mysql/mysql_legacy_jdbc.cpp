
#include <mysql/jdbc.h>
#include <iostream>
#include <cstdlib>
//prior to Connector/C++ 8.0.16
//#include <jdbc/mysql_connection.h>
//#include <jdbc/mysql_driver.h>
//#include <jdbc/cppconn/prepared_statement.h>

class MySQL_DB {
   private:
      sql::Driver* mDriver = nullptr;
      sql::Connection* mConnection = nullptr;
      static MySQL_DB* mDB_Instance;

   public:
      MySQL_DB(){
         mDriver = get_driver_instance();
         mConnection = mDriver->connect("tcp://localhost:3306", "marlon_cpp", "Mc0489921%"); 
         mConnection->setSchema("school");
      }
      ~MySQL_DB(){ delete this; }
     
     static MySQL_DB* getInstance(){
	if(mDB_Instance == nullptr){
	   mDB_Instance = new MySQL_DB();
        }
        return mDB_Instance;
     }
 
    sql::Connection* startConnection(){
        return mConnection;
    }
};

struct Student {
   int college_id;
   std::string name;
   std::string birthday;
   float grade;
};

void insertIntoDB(Student& student){
   sql::PreparedStatement* prepStmt;
   //get DB connection
   sql::Connection *conn = 
      MySQL_DB::getInstance()->startConnection();
  std::cout << "\n You have successfully connected to Database." << std::endl;

   prepStmt = conn->prepareStatement(
      "INSERT INTO student(College_ID, Name, Birthday, Grade) VALUES(?, ?, ?, ?)");

  prepStmt->setInt(1, student.college_id);
   prepStmt->setString(2, student.name.c_str());
    prepStmt->setString(3, student.birthday.c_str());
     prepStmt->setInt(4, student.grade);

   prepStmt->execute();
  delete prepStmt;
  delete conn;
}

MySQL_DB* MySQL_DB::mDB_Instance = nullptr;

int main(int argc, char* argv[]){

   Student student;
    student.college_id = 489;
    student.name = "Lazaro de Jesus";
    student.birthday = "1959-08-11";
    student.grade = 9.54;

  try{
      insertIntoDB(student);
      std::cout << "\n New entry has been created in Database!" << std::endl;
  }
  catch(const std::runtime_error& ex){
     std::cerr << " ERROR: " << ex.what() << std::endl;
  }

  std::cout << " ::: PROGRAM HAS ENDED ::: " << std::endl;

  return 0;
}


