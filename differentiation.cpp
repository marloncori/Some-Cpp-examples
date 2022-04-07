#include <iostream>
#include <cmath>
#include <windows.h>
#include <array>
#include <iomanip>
#include <vector>

#define MAX_SIZE 11
/* differential equations solver for polynomials
 
    steps for implementation:
    1 - define polynomial degree
    2 - define polynomial constants
    3 - construct polynomials using 1 and 2
    4 - define the point x to do differentiation for
    5 - do differentiation using an ODE
    6 - print out differentiation result 
    
    y = coef[0] + coef[1]*x^1 + coef[2]*x^2 + ...
    */
int degrees {};

void adorn(bool);
std::array<int, MAX_SIZE> gather_data();
void display_polynomial(std::array<int, MAX_SIZE>&, const int&);
float get_point_x_for_diff();
float get_y_value(std::array<int, MAX_SIZE>, const int&, const float);
float get_h_offset();
float differentiate(std::vector<float>&);
void show_result(const float);

int main(){
    
    std::array<int, MAX_SIZE> polynomial {{}};
    std::vector<float> params;
    float x0, y0 {};
    float h_offset, slope {};

    polynomial = gather_data();
    display_polynomial(polynomial, degrees);
    x0 = get_point_x_for_diff();
    y0 = get_y_value(polynomial, degrees, x0);
    h_offset = get_h_offset();
    float x1 = x0 + h_offset;
    
    params.push_back(h_offset);
    params.push_back(y0);
    float y1 = get_y_value(polynomial, degrees, x1);
    params.push_back(y1);
    
    slope = differentiate(params);
    show_result(slope);

    return 0;
}

void adorn(bool second=false){
    std::string line("=======================================================");
    if(!second){
        std::cout << "\n" << line << std::endl;
        std::cout << "       P o l y n o m i a l    s o l v er " << std::endl;
        std::cout << line << std::endl;
    } else {
        std::cout << "\n" << line << std::endl;
        std::cout << "        E n d     o f    p r o g r a m " << std::endl;
        std::cout << line << std::endl;
    }
}

std::array<int, MAX_SIZE> gather_data(){
    int degree;
    std::array<int, MAX_SIZE> coefficients {{}};

    adorn();
    std::cout << "\n  Please provide below the degree of the polynomial. " << std::endl;
    Sleep(1);
    std::cout << "       [ MAXIMUM VALUE: degree 10 ]\n" << std::endl;
    Sleep(1);
    std::cout << std::setw(7) << " ====> Degree: ";
    std::cin >> degree;
    std::cout << "\n  Now please enter the polynomial contants. " << std::endl;

    for(size_t i {0}; i <= degree; i++){
        std::cout << std::setw(5) << " ===> coefficient " << i << ": ";
        std::cin >> coefficients[i];
    }
    degrees = degree;
    return coefficients;
}
 
void display_polynomial(std::array<int, MAX_SIZE>& coeff, const int& size){
    std::cout<< "\n  So this is how the polynomial looks like: " << std::endl;
    for(int i {0}; i <= degrees; i++){
        if(i == 0){
            std::cout << " f(x) = " << std::setw(4) 
            << coeff[i] << " + ";
        }
         else if(i == degrees){
             std::cout << std::setw(4) 
             << coeff[i] << "*X^" << i << std::endl;
         }     
           else {
             std::cout << std::setw(4) 
             << coeff[i] << "*X^" << i << " + ";
        }
        Sleep(1);
    }
}

float get_point_x_for_diff(){
    float x;
    std::cout << std::endl;
    adorn();
    std::cout << "   Now please provide the float value in X axis \n where the differentiation should start." << std::endl;
    std::cout << "     ===> X :";
    std::cin >> x;
    std::cout << "\n   So you have chosen the value: " << std::setprecision(4) << x << ". " << std::endl;
    
    return x;
}

float get_y_value(std::array<int, MAX_SIZE> equation, const int& degree, const float x){
    float y {0.0};
    
    std::cout << "\n Degree of polynomial: " << degree << std::endl;
    std::cout << "    Starting calculations to solve for f(x)..." << std::endl;
    Sleep(2);
    std::cout << std::endl;

    for(int i {0}; i <= degree; i++){
        y += equation[i] * pow(x, i);
        std::cout << "    Partial value of y: " << y << std::endl;
        Sleep(1);
    }
    std::cout << "\n\tFinal value of Y: " << y << std::endl;
    return y;
}

float get_h_offset(){
    float h {};
    std::cout << "\n And now what should the H offset be?" << std::endl;
    std::cout << "  [ Choose a small float value between 0 and 1]" << std::endl;
    std::cout << "   ====> h: ";
    std::cin >> h;
    std::cout << "     You have chosen: h = " << h << std::endl;
    std::cout << "\n    So let us differeniate the polynomial now..." << std::endl;
    Sleep(2);
    return h;
}

float differentiate(std::vector<float>& Xs_and_Ys){
    float h = Xs_and_Ys[0];
    float y0 = Xs_and_Ys[1];
    float y1 = Xs_and_Ys[2];

    float slope = (y1 - y0) / h;
    return slope;
}

void show_result(const float slope){
    std::cout << "\n   The result of the differentiation is: \n"
    << std::setw(10) << std::setprecision(4) << "slope: " << slope << std::endl;

    adorn(true);
}