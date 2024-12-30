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
    // ������������
    Matrix();
    Matrix(int rows, int cols);
    Matrix(const vector<vector<double>>& data);

    // ���������
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

    // ������ ��� ������ � ���������
    Matrix transpose() const;
    Matrix inverse() const;
    Matrix pow(int exponent) const;
    double determinant() const;
    double norm() const;

    // ������ ��� �������� ���� �������
    bool isSquare() const;
    bool isDiagonal() const;
    bool isZero() const;
    bool isIdentity() const;
    bool isSymmetric() const;
    bool isUpperTriangular() const;
    bool isLowerTriangular() const;

    // ������ ��� �����-������
    void input();
    void print() const;

    // ��������������� ������
    int getRows() const { return rows; }
    int getCols() const { return cols; }
    vector<vector<double>> getData() const { return data; }

    // ����������� ����� ��� �������� ��������� �������
    static Matrix identity(int size);
};
