#include "pugixml.hpp"
#include <iostream>

int main()
{
    pugi::xml_document doc;
    if (!doc.load_file("../student_data.xml")) return -1;


    pugi::xml_node panels = doc.child("data");

    std::cout << panels.name() << std::endl;

    for (pugi::xml_node panel = panels.first_child(); panel; panel = panel.next_sibling())
    {
        std::cout << panel.name() << std::endl;

        for (pugi::xml_attribute attr = panel.first_attribute(); attr; attr = attr.next_attribute())
        {
            std::cout << " " << attr.name() << "=" << attr.value() << std::endl;
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
  return 0;
}