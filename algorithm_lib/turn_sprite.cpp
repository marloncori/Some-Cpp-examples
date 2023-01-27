#include <iostream>
#include <vector>
#include <cmath>

using Vec = std::vector<double>;
using Mat = std::vector<Vec>;

std::string line("\033[1;33m--------------------------------------------------\033[0m");
constexpr float PI = 3.14159;

struct Sprite {
    std::string kind;
    Vec position;
};

auto MatVecMul(const Mat& matr, const Vec& vect) -> Vec {
    auto result = Vec(matr.size());
    for(auto i = Vec::size_type{}; i < matr.size(); i += 1){
       for(auto j = Vec::size_type{}; j < vect.size(); j += 1){
           result[i] += matr[i][j] * vect[j];
       }
    }
    return result;
}

auto Rotate(double turn) -> Mat {
    auto rad = 2.0 * PI * turn;
    Mat rotMat = {{std::cos(rad), -std::sin(rad)}, {std::sin(rad), std::cos(rad)}};
    return rotMat;
}

auto main() -> int {
    auto sprite = Sprite{.kind = "Robot",
        .position = {-2.5, 3.4}
    };

    std::cout << line << std::endl;
    std::cout << "\n\033[1;34m " << sprite.kind
     << "\'s\033[0m \033[1;36mprevious position was:\n\t\033[0m" <<
     " \033[1;33m{ " << sprite.position[0] << ", " << sprite.position[1] << "}\033[0m." << std::endl;

    std::cout << line << std::endl;
    auto viewPos = MatVecMul(
        Rotate(-1.0/4.0), sprite.position
    );

    std::cout << "\n\033[1;34m " << sprite.kind
     << "\033[0m \033[1;36mrotated to position\033[0m" <<
     " \033[1;32m{ " << viewPos[0] << ", " << viewPos[1] << "}\033[0m." << std::endl;
 
    std::cout << line << std::endl;

  return 0;
}