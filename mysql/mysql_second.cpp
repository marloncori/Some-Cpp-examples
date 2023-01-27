#include <mysql.h>
#include <mysqld_error.h>

#include <iostream>
#include <cstdlib>
#include <cstdio>
#include <string.h>
#include <stdexcept>

namespace millenium {
    struct mysql_details {
      std::string Host;
      std::string User;
      std::string Password;
      std::string Database;
      unsigned int Port;
   };

    MYSQL* mysql_setup_connection(mysql_details mysql_info){
        MYSQL* conn = mysql_init(NULL);
        if(!mysql_real_connect(conn, mysql_info.Host.c_str(), mysql_info.User.c_str(), mysql_info.Password.c_str(), 
             mysql_info.Database.c_str(), mysql_info.Port, NULL, 0)){
            std::cerr << "\x1b[1;31m\n ERROR: Some database info is wrong \n or the requested database does not exist.\x1b[0m" << std::endl;
            std::cout << "\x1b[1;31m" << mysql_error(conn) << "\x1b[0m" << std::endl;
        }
        else {
            std::cout << "\n\n\x1b[1;32m -------------------------------------------------\x1b[0m" << std::endl;
            std::cout << "\x1b[1;35m  --> Connection to database\x1b[0m \x1b[1;34msuccessful\x1b[0m! \n  \x1b[1;35mYou are\x1b[0m \x1b[1;34mlogged in.\x1b[0m\n" << std::endl;
        }
        return conn;
    }

    MYSQL_RES* mysql_execute_query(MYSQL* connection, const char* my_query){
        if(mysql_ping(connection)){
           std::cerr << "\x1b[1;31m\\n ERROR: Impossibe to connect to database...\x1b[0m" << std::endl;
           std::cout << mysql_error(connection) << std::endl;
        }
        
        if(mysql_query(connection, my_query)){
            std::cerr << "\x1b[1;31m\n ERROR: Not possible to process sql query. Check your syntax.\x1b[0m" << std::endl;
            std::cout << "\x1b[1;31m" << mysql_error(connection) << "\x1b[0m" << std::endl; 
            rewind(stdin);
            getchar();
        }
        else {
          std::cout << "\x1b[1;32m ----------------------------------------------------------------\x1b[0m" << std::endl;
          std::cout << "\x1b[1;35m  --> Query sent to database\x1b[0m \x1b[1;34msuccessfully\x1b[0m \x1b[1;35mprocessed!\n\x1b[0m" << std::endl;
          std::cout << "\x1b[1;32m ----------------------------------------------------------------\x1b[0m" << std::endl;
 
        }
        return mysql_use_result(connection);
    }
}

int main(int argc, char* argv[]){

    MYSQL* connection;
      MYSQL_RES* response;
        MYSQL_ROW row;

    millenium::mysql_details params;
      params.Host     = "localhost";
      params.User     = "marlon_cpp";
      params.Password = "Mc0489921%";
      params.Database = "school";
      params.Port     =  3306;

     connection = millenium::mysql_setup_connection(params);

      std::string query1("SELECT * FROM student WHERE College_ID = 37;"); 
      std::string query2("SELECT * FROM student WHERE Name = \'Marlon Couto\';"); 
     
     response = millenium::mysql_execute_query(connection, query1.c_str());
     std::cout << "\x1b[1;33m\n This is the raw output of your first query:\n\t\x1b[0m";

    if(response){
        while((row = mysql_fetch_row(response)) != NULL){
            std::cout << "\x1b[1;33m ----------------------------------------------------------------\x1b[0m" << std::endl;
            std::cout << "\t | \x1b[1;32m" << row[0] << "\x1b[0m | \x1b[1;34m" <<  row[1] << "\x1b[0m | \x1b[1;35m" << row[2] << "\x1b[0m | \x1b[1;36m" << row[3] << "\x1b[0m |" << std::endl;        
           std::cout << "\t\x1b[1;33m ------------------------------------------------------------------\x1b[0m" << std::endl;
        }
    }
    else {
        std::cout << "\x1b[1;31m\n EMPTY RESPONSE! Nothing has been found on table \n  in accordance with the query definition...\x1b[0m" << std::endl;
    }
     
     response = millenium::mysql_execute_query(connection, query2.c_str());
     std::cout << "\x1b[1;33m\n This is the raw output of your second query:\n\t\x1b[0m";
    if(response){
        while((row = mysql_fetch_row(response)) != NULL){
            std::cout << "\x1b[1;33m -----------------------------------------------------------------\x1b[0m" << std::endl;
            std::cout << "\t | \x1b[1;32m" << row[0] << "\x1b[0m | \x1b[1;34m" <<  row[1] << "\x1b[0m | \x1b[1;35m" << row[2] << "\x1b[0m | \x1b[1;36m" << row[3] << "\x1b[0m |" << std::endl;
            std::cout << "\t\x1b[1;33m -------------------------------------------------------------------\x1b[0m" << std::endl;
        }
    }
    else {
        std::cout << "\x1b[1;31m\n EMPTY RESPONSE! Nothing has been found on table \n  in accordance with the query definition...\x1b[0m" << std::endl;
    }
    

    mysql_free_result(response);
    mysql_close(connection);

    return 0;
}