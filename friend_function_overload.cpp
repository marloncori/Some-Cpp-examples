#include<iostream>
#include<memory>

constexpr size_t size = 3;

class Vector {
    public:
        int v[size];
        Vector();
        Vector(std::unique_ptr<int> x);
        friend int operator[](int a, Vector b);
        friend Vector operator*(int a, Vector b);
        friend Vector operator*(Vector b, int a);
        friend std::istream& operator>>(std::istream&, Vector&);
        friend std::ostream& operator<<(std::ostream&, Vector&);
};

Vector::Vector(){
  for(int i=0; i<size; i++){
        v[i]=0;
   }
}

Vector::Vector(std::unique_ptr<int> x) {
  for(int i=0; i<size; i++){
     v[i] = x[i];
  }
}

int operator[](int a, Vector b){
    return b.v[a];
}

Vector operator*(int a, Vector b) {
   Vector c;
  for(int i=0; i<size; i++){
     c.v[i] = a*b.v[i];
  }
 return c;
}

Vector operator *(Vector b, int a){
  Vector c;
   for(int i=0; i<size; i++){
     c.v[i] = b.v[i] *a;
   }
  return c;
}

std::istream& operator>>(std::istream& din, Vector& b){
    for(int i=0; i<size; i++){
       din >> b.v[i];
    }
  return(din);
}

std::ostream& operator>>(std::ostream& dout, Vector& b) {
  dout << "(" <<b.v[0];
  for(int i=1; i<size; i++){
      dout << "," <<b.v[i];
  }
  dout<< ")";
 return (dout);
}


int main() {

   Vector m; Vector w;
 
    std::cout << "\nEnter the elements of vector m: " << std::endl;
    std::cin >> m;
    std::cout << "\n";

    std::cout << " m = " << m << std::endl;

  Vector* p = new Vector();
  Vector* q = new Vector(std::make_unique<int>(17));
  
    *p = 2 * m;
    *q = 4 * w;

    std::cout << std::endl;
    std::cout<< " p = "<< *p << std::endl;
    std::cout<< "\t q = "<< *q << std::endl;

return 0;
}