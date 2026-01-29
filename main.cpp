#include <iostream>
#include <vector>
#include <clocale>

namespace math {
    class Matrix {
    private:
        int rows, cols;
        std::vector<std::vector<double>> data;

    public:
        Matrix(int r = 0, int c = 0) : rows(r), cols(c), 
            data(r, std::vector<double>(c, 0.0)) {}

        // Assignment operators
        Matrix& operator+=(const Matrix& other) {
            if (rows == other.rows && cols == other.cols) {
                for (int i = 0; i < rows; ++i)
                    for (int j = 0; j < cols; ++j)
                        data[i][j] += other.data[i][j];
            }
            return *this;
        }

        Matrix& operator-=(const Matrix& other) {
            if (rows == other.rows && cols == other.cols) {
                for (int i = 0; i < rows; ++i)
                    for (int j = 0; j < cols; ++j)
                        data[i][j] -= other.data[i][j];
            }
            return *this;
        }

        Matrix& operator*=(double scalar) {
            for (int i = 0; i < rows; ++i)
                for (int j = 0; j < cols; ++j)
                    data[i][j] *= scalar;
            return *this;
        }

        // I/O operators
        friend std::ostream& operator<<(std::ostream& os, const Matrix& m) {
            for (int i = 0; i < m.rows; ++i) {
                for (int j = 0; j < m.cols; ++j) {
                    os << m.data[i][j] << "\t";
                }
                os << std::endl;
            }
            return os;
        }

        friend std::istream& operator>>(std::istream& is, Matrix& m) {
            for (int i = 0; i < m.rows; ++i)
                for (int j = 0; j < m.cols; ++j)
                    is >> m.data[i][j];
            return is;
        }

        void print() const { std::cout << *this; }
    };
}

int main() {
    setlocale(LC_ALL, "en_US.UTF-8");

    math::Matrix m(2, 2), m1(2, 2);

    std::cout << "Enter elements for matrix m (4 numbers):" << std::endl;
    std::cin >> m;
    
    std::cout << "Enter elements for matrix m1 (4 numbers):" << std::endl;
    std::cin >> m1;

    m += m1;
    std::cout << "Result of m += m1:" << std::endl << m;

    m *= 10.5;
    std::cout << "Result of m *= 10.5:" << std::endl << m;

    return 0;
}
