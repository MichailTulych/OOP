#pragma once
#include <iostream>
#include <vector>

using namespace std;
class Matrix {
private:
    vector<vector<double>> data;
    int rows;
    int cols;

public:
    // Конструкторы
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const vector<vector<double>>& data);

    // Операторы
    Matrix operator+(const Matrix& other) const;
    Matrix operator-(const Matrix& other) const;
    Matrix operator*(const Matrix& other) const;
    Matrix operator*(double scalar) const;
    Matrix operator/(double scalar) const;
    Matrix& operator+=(const Matrix& other);
    Matrix& operator-=(const Matrix& other);
    Matrix& operator*=(const Matrix& other);
    Matrix& operator*=(double scalar);
    Matrix& operator/=(double scalar);
    bool operator==(const Matrix& other) const;
    bool operator!=(const Matrix& other) const;

    // Методы для работы с матрицами
    Matrix transpose() const;
    Matrix inverse() const;
    Matrix pow(int exponent) const;
    double determinant() const;
    double norm() const;

    // Методы для проверки типа матрицы
    bool isSquare() const;
    bool isDiagonal() const;
    bool isZero() const;
    bool isIdentity() const;
    bool isSymmetric() const;
    bool isUpperTriangular() const;
    bool isLowerTriangular() const;

    // Методы для ввода-вывода
    void input();
    void print() const;

    // Вспомогательные методы
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    vector<vector<double>> getData() const { return data; }

    // Статический метод для создания единичной матрицы
    static Matrix identity(int size);
};
