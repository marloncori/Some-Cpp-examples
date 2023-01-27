
#include "Matrix3D.h"
#define M_PI 3.14159

void showPoint(float outputMatrix[4][1]){
    std::cout<<"\n --> New vector: \n\t("<<outputMatrix[0][0]<<","<<outputMatrix[1][0]<<","<<outputMatrix[2][0]<<")\n"<<std::endl;
}

void multiplyMatrix(float rotationMatrix[4][4], float inputMatrix[4][1], float outputMatrix[4][1])
{
  for(int i = 0; i < 4; i++ ){
     for(int j = 0; j < 1; j++){
        outputMatrix[i][j] = 0;
        for(int k = 0; k < 4; k++){
          outputMatrix[i][j] += rotationMatrix[i][k] * inputMatrix[k][j];
        }
      }
  }
}

void setUpRotationMatrix(float rotationMatrix[4][4], float angle, float u, float v, float w)
{
    float L = (u*u + v * v + w * w);
    angle = angle * M_PI / 180.0; //converting to radian value
    float u2 = u * u;
    float v2 = v * v;
    float w2 = w * w; 
 
    rotationMatrix[0][0] = (u2 + (v2 + w2) * cos(angle)) / L;
    rotationMatrix[0][1] = (u * v * (1 - cos(angle)) - w * sqrt(L) * sin(angle)) / L;
    rotationMatrix[0][2] = (u * w * (1 - cos(angle)) + v * sqrt(L) * sin(angle)) / L;
    rotationMatrix[0][3] = 0.0; 
 
    rotationMatrix[1][0] = (u * v * (1 - cos(angle)) + w * sqrt(L) * sin(angle)) / L;
    rotationMatrix[1][1] = (v2 + (u2 + w2) * cos(angle)) / L;
    rotationMatrix[1][2] = (v * w * (1 - cos(angle)) - u * sqrt(L) * sin(angle)) / L;
    rotationMatrix[1][3] = 0.0; 
 
    rotationMatrix[2][0] = (u * w * (1 - cos(angle)) - v * sqrt(L) * sin(angle)) / L;
    rotationMatrix[2][1] = (v * w * (1 - cos(angle)) + u * sqrt(L) * sin(angle)) / L;
    rotationMatrix[2][2] = (w2 + (u2 + v2) * cos(angle)) / L;
    rotationMatrix[2][3] = 0.0; 
 
    rotationMatrix[3][0] = 0.0;
    rotationMatrix[3][1] = 0.0;
    rotationMatrix[3][2] = 0.0;
    rotationMatrix[3][3] = 1.0;
} 