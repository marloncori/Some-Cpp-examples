#include <iostream>
#include <vector>
#include <stdlib.h>

using namespace std;

class Matrix{

private:
    size_t ROW,COL;
    vector<float> mat;
public:
    Matrix(size_t N, size_t M, float populate = 0.0){
        this->ROW = N;
        this->COL = M;
        this->mat = vector<float> (ROW,float (COL,populate));
    }
    Matrix(size_t N, int populate = 0){
        this->ROW = N;
        this->COL = N;
        this->mat = vector<float> (ROW,float(COL,populate));
    }
    void __init(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cin  >> this->mat[i][j];
            }
        }
    }
    void __display(){
        for(int i = 0; i < ROW; ++i){
            for(int j = 0; j < COL; ++j){
                cout << this->mat[i][j] << " ";
            }
            cout << "\n";
        }
    }
    int operator*(const Matrix &rhs)const{
        if(this->COL != rhs.ROW){
            throw "MATRIX MULTIPLICATION CANNOT HAPPEN WITH THE GIVEN MATRICES";
        }
        int result(this->ROW,rhs.COL);
        for(int _i = 0; _i < this->ROW; _i++){
            for(int _j = 0; _j < rhs.COL; _j++){
                result[_i][_j] = 0;
                for(int _k = 0; _k < this->COL; ++_k){
                    result[_i][_j]+=(this->mat[_i][_k]*rhs.mat[_k][_j]);
                }
            }
        }
        return result;
    }
    int power(int n){
        if(n == 0)return Matrix<T>(this->ROW, this->COL,1);
        if(n == 1)return *this;
        int p = power(n/2);
        p = p*p;
        if(n%2)p = p*(*this);
        return p;
    }
    int determinant(){
        float det;
        for(int i = 0; i < this->ROW; i++)
            det = det + (this->mat[0][i] * (this->mat[1][(i+1)%3] * this->mat[2][(i+2)%3] - this->mat[1][(i+2)%3] * this->mat[2][(i+1)%3]));
        return det;
    }
    void inverse(){
     float det = determinant();
     cout << "Inverse matrix = [";
     for(int i = 0; i < this->ROW; i++){
        for(int j = 0; j < this->COL; j++){
            cout << ((this->mat[(j+1)%3][(i+1)%3] * this->mat[(j+2)%3][(i+2)%3]) - (this->mat[(j+1)%3][(i+2)%3] * this->mat[(j+2)%3][(i+1)%3])/ det);
            cout << "\n";
            }
         }
         cout << "]" << endl;
     }
    void tranpose(){
        int transp[this->ROW][this->COL];
      // Computing transpose of the matrix
      for (int i = 0; i < this->ROW; ++i){
         for (int j = 0; j < this->COL; ++j){
          transp[j][i] = this->mat[i][j];
        }
      }
     // Printing the transpose
     cout << "\nTranspose of Matrix: " << endl;
     for (int i = 0; i < this->COL; ++i){
        for (int j = 0; j < this->ROW; ++j){
           cout << " " << transp[i][j];
           if (j == this->ROW - 1)
             cout << endl << endl;
          }
       }
    }
};

int main(int argc, char** argv){

    Matrix::Matrix R(3, 3);

    R.__init();
    R.__display();

    return 0;
}
