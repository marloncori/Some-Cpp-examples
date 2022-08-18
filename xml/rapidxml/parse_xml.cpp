#include <iostream>
#include <fstream>
#include <vector>
#include <string>
#include <windows.h>
#include <C:/Users/user/Desktop/src/xml/rapidxml/rapidxml.hpp>

using namespace rapidxml;

xml_document<> doc;
xml_node<> *rootNode = NULL;
std::string fileName("student_data.xml");

int main(int argc, char* argv[]) {

 std::cout << "\x1b[1;36m ------------------------------------- \x1b[0m" << std::endl;
 std::cout << "\x1b[1;34m   XML Parser by RapidXml version=1.0 \x1b[0m" << std::endl;
 std::cout << "\x1b[1;36m ------------------------------------- \x1b[0m" << std::endl;
 Sleep(2000);

 std::cout << "\n\x1b[1;32m File\x1b[0m \x1b[1;33m\'" << fileName << "\'\x1b[0m \x1b[1;32mwill be parsed...\x1b[0m" << std::endl;

 // read file
 std::ifstream sampleFile("student_data.xml");
 std::vector<char> buffer(
   (std::istreambuf_iterator<char>(sampleFile)), std::istreambuf_iterator<char>()
 );

 buffer.push_back('\0');

 //parse chars buffer
 doc.parse<0>(&buffer[0]);

 //find out root node
 rootNode = doc.first_node("data");

 //iterate over student nodes
 for(xml_code<> *studentNode = rootNode->first_node("student"); studentNode; studentNode = studentNode->next_sibling())
 {
    std::cout << "\n\t [STUDENT TYPE] : " << studentNode->first_attribute("std_type")->value() << std::endl;
    Sleep(1000);

    //iterate over student first names
    for(xml_code<> *studentNameNode = studentNode->first_node("firstname"); studentNameNode; studentNameNode = studentNameNode->next_sibling()) 
    {
       std::cout << "\n\t  [FIRST NAME] : " << studentNameNode->value() << std::endl;
       Sleep(1000);
    }

    //iterate over student last names
    for(xml_code<> *studentLastNameNode = studentNode->first_node("lastname"); studentLastNameNode; studentLastNameNode = studentLastNameNode->next_sibling()) 
    {
       std::cout << "\n\t  [LAST NAME] : " << studentLastNameNode->value() << std::endl;
       Sleep(1000);
    }
    Sleep(2000);
 }

 return 0;
}
