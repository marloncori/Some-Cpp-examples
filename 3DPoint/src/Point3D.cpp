#include <ostream>
#include "Point3D.h"

std::ostream& operator<<(std::ostream& out, Point3D& p){
     std::string line("\033[1;33m\n======================\n\033[0m");	
     out << line << "  3D POINT " << line << "\tx: " << p.x << "\n\ty: " << p.y << "\n\tz: " << p.z << line;
   return out;
}

void translate(Point3D& point3D, float tX, float tY, float tZ){
    point3D.x += tX;
    point3D.y += tY;
    point3D.z += tZ;
    std::cout << "\033[1;32m  --> Point successfully translated. \033[0m" << std::endl;
}

void rotateX(Point3D& point3D, float angle){
     angle = angle * PI / 180.0;
     auto temp = point3D.y;
     point3D.y *= (std::cos(angle) - point3D.z * std::sin(angle));
     point3D.z = temp * std::sin(angle) + point3D.z * std::cos(angle);
     std::cout << "\033[1;34m >> Point has rotated about X axis! \033[1;0m" << std::endl; 	
}

void rotateY(Point3D& point3D, float angle){
     angle = angle * PI / 180.0;
     auto temp = point3D.z;
     point3D.z *= (std::cos(angle) - point3D.x * std::sin(angle));
     point3D.x = temp * std::sin(angle) + point3D.x * std::cos(angle);
     std::cout << "\033[1;35m >> Point has rotated about Y axis! \033[0m" << std::endl; 	
}


void rotateZ(Point3D& point3D, float angle){
     angle = angle * PI / 180.0;
     auto temp = point3D.x;
     point3D.x *= (std::cos(angle) - point3D.y * std::sin(angle));
     point3D.y = temp * std::sin(angle) + point3D.y * std::cos(angle);
     std::cout << "\033[1;36m >> Point has rotated about Z axis! \033[0m" << std::endl; 	
}

void scale(Point3D& point3D, float sf, float xf, float yf, float zf){
    point3D.x *= (sf + (1 - sf) * xf);
    point3D.y *= (sf + (1 - sf) * yf);
    point3D.z *= (sf + (1 - sf) * zf); 
    std::cout << " >> Point has been scaled!" << std::endl; 	
}