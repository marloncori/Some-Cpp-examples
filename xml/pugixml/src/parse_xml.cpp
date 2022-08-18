#include <iostream>
#include <string>
#include <windows.h>
#include "pugixml.hpp"

using namespace pugi;

int main(){

 xml_document doc;

 std::cout << "\x1b[1;36m ------------------------------------- \x1b[0m" << std::endl;
 std::cout << "\x1b[1;34m   XML Parser by PugiXML version=1.0 \x1b[0m" << std::endl;
 std::cout << "\x1b[1;36m ------------------------------------- \x1b[0m" << std::endl;
 Sleep(2000);

 std::cout << "\n\x1b[1;32m File\x1b[0m \x1b[1;33m\'" << fileName << "\'\x1b[0m \x1b[1;32mwill be parsed...\x1b[0m" << std::endl;

 // load the XML file
 if(!doc.load_file("../student_data.xml")){
    return -1;
 }

 xml_node tools = doc.child("data").child("student");

 for(xml_node_iterator it = tools.begin(); it != tools.end(); ++it){
    std::cout << "\n\t [STUDENT] : \n\t";
    
   for(xml_attribute_iterator ait = it->attributes_begin(); ait != it->attributes_end(); ++ait){
       std::cout << " " << ait->name() << " = " << ait->value();
   }
   std::cout << std::endl;
   Sleep(1000);
  }

 return 0;
}