#include <iostream>
#include <clocale>
#include "matrix.h"

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    math::Matrix m(2, 2), m1(2, 2);

    std::cout << "Enter 4 numbers for matrix M:" << std::endl;
    std::cin >> m;
    
    std::cout << "Enter 4 numbers for matrix M1:" << std::endl;
    std::cin >> m1;

    // Проверка +=
    m += m1;
    std::cout << "After m += m1:" << std::endl << m;

    // Проверка *= на число
    m *= 2.0;
    std::cout << "After m *= 2.0:" << std::endl << m;

    return 0;
}
