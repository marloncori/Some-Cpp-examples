#include <iostream>
#include <cstdlib>

#include <jdbc/mysql_driver.h>
#include <jdbc/mysql_connection.h>
#include <jdbc/cppconn/*.h>

struct DB_Connection {
    const char* server;
    const char* user;
    const char* password;
    const char* database;
};

MYSQL* mysql_connect_setup(struct DB_Connection db_connector){
    MYSQL* connection = mysql_init(NULL);
    if(!mysql_real_connect(connection, db_connector.server,
      db_connector.user, db_connector.password, db_connector.database, 0, NULL, 0)){
          std::cerr << "\n Connection error: " << mysql_error(connection) << std::endl;
          exit(1);
    }
    return connection;
}
                                        // it cannot be a std::string
MYSQL_RES* mysql_execute_query(MYSQL* connection, const char* sql_query){
    if(mysql_query(connection, sql_query)){
        std::cerr << "\n MySQL Query error: " << mysql_error(connection) << std::endl;
        exit(1);
    }

    return mysql_use_result(connection);
}

int main(){
    std::string line("\n----------------------------------------------------------------------------------\n");
    std::string title(" | id  |     name     |    surname     |            email              |   phone number  |\n");
    MYSQL* conn;
    MYSQL_RES* res;
    MYSQL_ROW row;

    struct DB_Connection mysqlDB;
    mysqlDB.server = "localhost";
    mysqlDB.user = "root";
    mysqlDB.password = "Mc0489921%";

    conn = mysql_connect_setup(mysqlDB);
    res = mysql_execute_query(conn, "select * from personal_data;");

    std::cout << " Displaying database output..." << std::endl;
    
    std::cout << line << std::endl;
    std::cout << title << std::endl;
    std::cout << line << std::endl;

    while((row = mysql_fetch_row(res)) != NULL){
        std::cout << row[0] <<  " | " << row[1] << " | "
        << row[2] <<  " | " << row[3] << " | " << row[4] << "\n" << std::endl;
   }
    std::cout << line << std::endl;
    std::cout << title << std::endl;
    std::cout << line << std::endl;

   mysql_free_result(res);
   mysql_close(conn);

   std::cout << "\n Connection to database has been closed. \n Thank you and good night!" << std::endl;

 return 0;
}

// to compile I need to write like this:
// g++ -o mysql_query mysql_connect.cpp -L 
// C:/Program Files/MySQL/MySQL Server 8.0/include/mysql
// -lmysqlclient