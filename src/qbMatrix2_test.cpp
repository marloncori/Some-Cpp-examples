#include <iostream>
#include <cmath>
#include <iomanip>
#include <cstring>
#include <windows.h>

#include "qbMatrix2.h"

std::string line("==========================================================");

void adorn(bool);
void showMatrix(qbMatrix2<double>&);
void fetchMatrixElements(qbMatrix2<double>&);

int main(){

 int testRows = 3;
 int testColumns = 4;

 double matrixElems[12] = {1.0, 2.0, 3.0, 4.0, 5.0, 6.0, 7.0, 8.0, 9.0, 10.0, 11.0, 12.0};
 double secondMatrixElems[12] = {1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0, 1.0, 2.0, 3.0};

 qbMatrix2<double> testMatrix(testRows, testColumns, matrixElems);
 std::cout << "\n  Let us start the test of the qbMatrix2 C++ Library!\n" << std::endl;
 Sleep(2);

 std::cout << line << std::endl;
 std::cout << " >>>> A 3x4 test Matrix has been built." << std::endl;
 Sleep(1);
 showMatrix(testMatrix);
 Sleep(2);

 std::cout << "\n" << line << std::endl;
 std::cout << "  And now let us start the test of matrix element retrieval." << std::endl;  
 fetchMatrixElements(testMatrix);
 Sleep(1);

 std::cout << "\n" << line << std::endl; 
 std::cout << "  Now let us test of matrix multiplication." << std::endl;  
 Sleep(1);
 
 qbMatrix2<double> testMatrix2(4, 3, secondMatrixElems);
 std::cout << " >>>> 4x3 second test matrix elements: " << std::endl; 
 showMatrix(testMatrix2);

 qbMatrix2<double> resultantMatrix = testMatrix * testMatrix2;
 Sleep(1);
 std::cout << " >>>> This is the resultant matrix of multiplying \n  the first and second test matrices: " << std::endl; 
 showMatrix(resultantMatrix);
 
 Sleep(1);
 std::cout << "  Now let us test matrix multiplication by vectors." << std::endl;  
 Sleep(1);
 
 double columnData[3] = {1.5, 2.5, 3.5};
 double squareData[9] = {1.0, 0.0, 0.0, 0.0, 1.0, 0.0, 0.0, 0.0, 1.0};
 
 qbMatrix2<double> testColumnVector(3, 1, columnData);
 qbMatrix2<double> testSquareMatrix(3, 3, squareData);

 std::cout << " >>>>>> Column vector: " << std::endl;
 showMatrix(testColumnVector);
 Sleep(1);
 
 
 std::cout << " >>>>>> Square matrix: " << std::endl;
 showMatrix(testSquareMatrix);
 Sleep(1);

 std::cout << " >>>>>> Column vector multiplied by square matrix: " << std::endl;
 Sleep(1);
 qbMatrix2<double> scalerMatrixProduct = testColumnVector * testSquareMatrix;
 showMatrix(scalerMatrixProduct);
 Sleep(1);

 std::cout << " >>>>>> Square matrix multiplied by column vector: " << std::endl;
 Sleep(1);
 qbMatrix2<double> matrixScalerProduct = testSquareMatrix * testColumnVector;
 showMatrix(matrixScalerProduct);
 Sleep(1);

 std::cout << "  Now let us test adding up two matrices." << std::endl;  
 Sleep(1);
 qbMatrix2<double> addedMatrix = resultantMatrix + testSquareMatrix;
 Sleep(1);
 showMatrix(addedMatrix);

 std::cout << " >>>>>> Square matrix plus 1.0: " << std::endl;
 qbMatrix2<double> newSquareMatrix = testSquareMatrix + 1.0;
 Sleep(1);
 showMatrix(newSquareMatrix);
 Sleep(1);

 std::cout << " >>>>>> Square matrix plus 1.0 multiplied by column vector: " << std::endl;
 Sleep(1);
 qbMatrix2<double> newMatrixScalerProduct = newSquareMatrix * testColumnVector;
 showMatrix(newMatrixScalerProduct);

 std::cout << "  Now let us test equality operator." << std::endl;  
 Sleep(1);
 std::cout << "\tIs test Matrix 1 equal to test matrix 2? " << (testMatrix == testMatrix2) << std::endl;
 Sleep(1);
  std::cout << "\tIs test Matrix 2 equal to test matrix 1? " << (testMatrix2 == testMatrix) << std::endl;
 Sleep(1);
 qbMatrix2<double> testMatrix3 = testMatrix;
 std::cout << "\tIs test Matrix 3 equal to test matrix 1? " << (testMatrix3 == testMatrix) << std::endl;
 Sleep(1);
 std::cout << "\tIs test Matrix 1 equal to test matrix 3? " << (testMatrix == testMatrix3) << std::endl;
 Sleep(1);

 std::cout << line << std::endl;
 std::cout << "  And now let us test substracting matrices and scaler." << std::endl;  
 Sleep(1);
 std::cout << " >>>>>> New square matrix minus test Matrix 3: " << std::endl;
 qbMatrix2<double> minusMatrix = newSquareMatrix - testMatrix3;
 showMatrix(minusMatrix);

 std::cout << " >>>>>>  Matrix 3 minus scaler 2.0: " << std::endl;
 qbMatrix2<double> minusMatrixScaler = testMatrix3 - 2.0;
 showMatrix(minusMatrixScaler);

 std::cout << " >>>>>>  Scaler 4.0 minus test matrix 2: " << std::endl;
 qbMatrix2<double> minusScalerMatrix = 4.0 - testMatrix2;
 showMatrix(minusScalerMatrix);

 adorn(true); 

 return 0;
}

void adorn(bool second = false){
    if(!second){
        std::cout << line << std::endl;
        std::cout << " ::: CUSTOM :: MATRIX :: LIBRARY :::" << std::endl;
        std::cout << line << std::endl;
    } else {
        std::cout << line << std::endl;
        std::cout << "  :::: END ::: OF ::: PROGRAM ::::" << std::endl;
        std::cout << line << std::endl;
    }
}

void showMatrix(qbMatrix2<double>& M){
    int rows =  M.getNumRows();
    int cols =  M.getNumCols();
    adorn();
    Sleep(1); 
    std::cout << "\n >>> This is the Matrix you have created: " << std::endl;
    Sleep(1);
    for(int i = 0; i < rows; ++i){
        for(int j = 0; j < cols; ++j){
            std::cout << std::setw(10) << M.getElement(i, j ) << " ";
            Sleep(0.5);
        }
    }

     std::cout << "\n >>> Thank you for using the Custom Matrix Library!" << std::endl;
     Sleep(0.5);
    adorn(true);
}

void fetchMatrixElements(qbMatrix2<double>& M){
        std::cout << std::setw(5) << "===> element(0,0): " << M.getElement(0,0) << std::endl;
    Sleep(0.5);
        std::cout << std::setw(5) << "===> element(1,0): " << M.getElement(1,0) << std::endl;
    Sleep(0.5);
        std::cout << std::setw(5) << "===> element(2,0): " << M.getElement(2,0) << std::endl;
    Sleep(0.5);
        std::cout << std::setw(5) << "===> element(0,1): " << M.getElement(0,1) << std::endl;
    Sleep(0.5);
        std::cout << std::setw(5) << "===> element(1,1): " << M.getElement(1,1) << std::endl;
    Sleep(0.5);
        std::cout << std::setw(5) << "===> element(2,1): " << M.getElement(2,1) << std::endl;
    Sleep(0.5);
        std::cout << std::setw(5) << "===> element(0,0): " << M.getElement(5,5) << std::endl;
    Sleep(0.5);
}