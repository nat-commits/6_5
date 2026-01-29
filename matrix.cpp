#include "matrix.h"
#include <iostream>
#include <cmath>

using namespace math;

// ... (ваши существующие методы operator(), print, +, -, *)

Matrix& Matrix::operator+=(const Matrix& other) {
    if (rows_ == other.rows_ && cols_ == other.cols_) {
        for (size_t i = 0; i < mvec_.size(); ++i) {
            mvec_[i] += other.mvec_[i];
        }
    }
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    if (rows_ == other.rows_ && cols_ == other.cols_) {
        for (size_t i = 0; i < mvec_.size(); ++i) {
            mvec_[i] -= other.mvec_[i];
        }
    }
    return *this;
}

Matrix& Matrix::operator*=(real scalar) {
    for (size_t i = 0; i < mvec_.size(); ++i) {
        mvec_[i] *= scalar;
    }
    return *this;
}

std::ostream& math::operator<<(std::ostream& os, const Matrix& m) {
    for (int i = 0; i < m.rows_; ++i) {
        for (int j = 0; j < m.cols_; ++j) {
            os << m.mvec_[m.cols_ * i + j] << "\t";
        }
        os << std::endl;
    }
    return os;
}

std::istream& math::operator>>(std::istream& is, Matrix& m) {
    for (size_t i = 0; i < m.mvec_.size(); ++i) {
        is >> m.mvec_[i];
    }
    return is;
}
