#include <iostream>
#include "Matrix3D.h"

using namespace std;

Point points; 
float rotationMatrix[4][4];
float inputMatrix[4][1] = {0.0, 0.0, 0.0, 0.0};
float outputMatrix[4][1] = {0.0, 0.0, 0.0, 0.0};

int main(){
    float angle;
    float u, v, w;
    cout<<"\tEnter the initial point you want to transform: \n";
    cout<< "\t --> x: ";
    cin>>points.x;
    cout<< "\t --> y: ";
    cin>>points.y;
    cout<< "\t --> z: ";
    cin>>points.z;

    inputMatrix[0][0] = points.x;
    inputMatrix[1][0] = points.y;
    inputMatrix[2][0] = points.z;
    inputMatrix[3][0] = 1.0; 
 
    cout<<"\tEnter axis vector: \n";
    cout<< "\t ==>> u: ";
    cin>>u;
    cout<< "\t ==>> v: ";
    cin>>v;
    cout<< "\t ==>> w: ";
    cin>>w;; 
 
    cout<<"\tEnter the rotating angle in degree: \n";
    cout << "\t ::: angle = ";
    cin>>angle; 
 
    setUpRotationMatrix(rotationMatrix, angle, u, v, w);
    multiplyMatrix(rotationMatrix, inputMatrix, outputMatrix);
    showPoint(outputMatrix); 

  return 0;
}