#ifndef POINT_3D_H
#define POINT_3D_H

#include <iostream>
#include <ostream>
#include <cmath>

#define PI 3.14159

typedef struct {
    float x;
    float y;
    float z;
} Point3D;

std::ostream& operator<<(std::ostream& out, Point3D& p);

void translate(Point3D& point3D, float tX, float tY, float tZ);
void rotateX(Point3D& point3D, float angle);
void rotateY(Point3D& point3D, float angle);
void rotateZ(Point3D& point3D, float angle);
void scale(Point3D& point3D, float sf, float xf, float yf, float zf);

#endif