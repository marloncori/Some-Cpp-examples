#ifndef MATRIX_3D_H
#define MATRIX_3D_H

#include <iostream>

typedef struct {
    float x;
    float y;
    float z;
} Point;

void showPoint(float outputMatrix[4][1]);

void multiplyMatrix(float rotationMatrix[4][4], float inputMatrix[4][1], float outputMatrix[4][1]);

void setUpRotationMatrix(float rotationMatrix[4][4], float angle, float u, float v, float w);

#endif