#pragma once
#include <vector>
#include <iostream>

namespace math
{
    typedef double real;

    class Matrix
    {
    private:
        int cols_;
        int rows_;
        std::vector<real> mvec_;
    public:
        Matrix(){};
        Matrix(int rows, int cols) : cols_(cols), rows_(rows), mvec_(std::vector<real>(rows * cols, 0.0)) {};

        real& operator()(int row, int col);
        real operator()(int row, int col) const;
        void print();

        // Новые операторы присваивания
        Matrix& operator+=(const Matrix& other);
        Matrix& operator-=(const Matrix& other);
        Matrix& operator*=(real scalar);

        // Дружественные функции
        friend Matrix operator+(const Matrix& A, const Matrix& B);
        friend Matrix operator-(const Matrix& A, const Matrix& B);
        friend Matrix operator*(const Matrix& A, const Matrix& B);
        
        // Операторы ввода-вывода
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m);
        friend std::istream& operator>>(std::istream& is, Matrix& m);
    };
}
