// MatrixWork.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include "Matrix.h"
int main()
{
    Matrix m1(5, 4);
    std::cout << u8"Исходная матрица -> " << std::endl;
    m1.printMatrix();
    Matrix m2(5, 4);
    std::cout << u8"Вторая матрица -> " << std::endl;
    m2.printMatrix();
    Matrix sum(5, 4), sub(5, 4);
    sum = m1 + m2;
    std::cout << u8"Сумма матриц -> " << std::endl;
    sum.printMatrix();
    sub = m1 - m2;
    std::cout << u8"Разница матриц -> " << std::endl;
    sub.printMatrix();
    m1++;
    std::cout << u8"Транспонированная матрица -> " << std::endl;
    m1.printMatrix();
}
