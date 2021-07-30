#include <vector>
#include <stdio.h>
#include <conio.h>

using namespace std;
class Matrix{
public:
  int rows, cols;
  double *cellData;   // this is our 2 dimensional array

  double &cells(int r, int c){   // use to access our 2-d array
    return cellData[r*cols+c];
    }

  Matrix(){
    rows = 1;
    cols = 1;
    cellData = new double[rows*cols];
    }

  ~Matrix(){    // clean up
    delete[] cellData;
    }
  Matrix operator=(Matrix a){
    rows = a.rows;
    cols = a.cols;

    delete[] cellData;
    cellData = new double[rows*cols];

    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        cells(i, j) = a.cells(i, j);   // copy matrix

    return *this;
    }

  void SetDimensions(int rows, int cols){
    Matrix::rows = rows;
    Matrix::cols = cols;

    delete[] cellData;   // delete old matrix cells
    cellData = new double[rows*cols];
    cells(0, 0) = 0.;
    }

  Matrix sum(Matrix a){
    Matrix ret;

    if(a.cols != cols || a.rows != rows)    // must be same size matrices
      return ret;    // return blank 1x1 matrix

    ret.SetDimensions(cols, rows);

    for(int i = 0; i < rows; i++)
      for(int j = 0; j < cols; j++)
        ret.cells(i, j) = cells(i, j) + a.cells(i, j);   // add 2 matrices together

    return ret;     // return summation result
    }
  };

int main(){
  Matrix x;
  x.SetDimensions(2, 2);

  printf("Blank matrix:\n");
  printf("%f %f\n%f %f\n\n",   x.cells(0, 0), x.cells(0, 1), x.cells(1, 0), x.cells(1, 1));

  // use your readmatrix() function here...
  x.cells(0, 0) = 1.;
  x.cells(0, 1) = 2.;
  x.cells(1, 0) = 3.;
  x.cells(1, 1) = 4.;

  printf("Populated matrix:\n");
  printf("%f %f\n%f %f\n\n",   x.cells(0, 0), x.cells(0, 1), x.cells(1, 0), x.cells(1, 1));

  x = x.sum(x);   // add to self
  printf("Matrix after summation:\n");
  printf("%f %f\n%f %f\n\n",   x.cells(0, 0), x.cells(0, 1), x.cells(1, 0), x.cells(1, 1));

  getch();

  return 0;
  }
