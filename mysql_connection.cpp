#include <mysqlx/xdevapi.h>
#include <iostream>
#include <cstdlib>
#include <stdexcept>

int main(){
    sql::mysql::MySQL_Driver *driver;
    sql::Connection *con;
   
    try{
        driver = sql::mysql::get_mysql_driver_instance();
        con   = driver->connect("tcp://localhost:3306", "marlon_cpp", "Mc0489921%");
        if(con->isValid())
            std::cout << "\n Connection with MySQL Db succcessfully stablished!" <<std::endl;
        else    
              std::cout << "\n Connection with MySQL Db has not been stablished!" <<std::endl;
    } 
    catch(const std::runtime_error &err){
        std::cerr << "\t An error has happened: " << err.what() << std::endl;
    }

    delete con;
    return 0;
}