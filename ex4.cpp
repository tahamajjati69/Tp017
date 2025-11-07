#ifndef MATRIX_H
#define MATRIX_H

#include <iostream>
#include <array>
#include <initializer_list>
#include <iomanip>

template <typename T, std::size_t N, std::size_t M>
class Matrix {
private:
    std::array<std::array<T, M>, N> data{};
public:
    Matrix() = default;

    Matrix(std::initializer_list<std::initializer_list<T>> init) {
        std::size_t i = 0;
        for (auto& row : init) {
            std::size_t j = 0;
            for (auto& val : row) {
                if (i < N && j < M) data[i][j] = val;
                ++j;
            }
            ++i;
        }
    }

    T& at(std::size_t i, std::size_t j) { return data.at(i).at(j); }
    const T& at(std::size_t i, std::size_t j) const { return data.at(i).at(j); }

    Matrix operator+(const Matrix& other) const {
        Matrix res;
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < M; ++j)
                res.data[i][j] = data[i][j] + other.data[i][j];
        return res;
    }

    template <std::size_t P>
    Matrix<T, N, P> operator*(const Matrix<T, M, P>& other) const {
        Matrix<T, N, P> res;
        for (std::size_t i = 0; i < N; ++i)
            for (std::size_t j = 0; j < P; ++j)
                for (std::size_t k = 0; k < M; ++k)
                    res.at(i,j) += data[i][k] * other.at(k,j);
        return res;
    }

    friend std::ostream& operator<<(std::ostream& os, const Matrix& mat) {
        for (std::size_t i = 0; i < N; ++i) {
            for (std::size_t j = 0; j < M; ++j)
                os << std::setw(5) << mat.data[i][j] << " ";
            os << "\n";
        }
        return os;
    }
};

#endif
