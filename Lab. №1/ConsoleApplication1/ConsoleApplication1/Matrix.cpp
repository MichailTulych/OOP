#include "Matrix.h"
#include <cmath>
#include <stdexcept>
using namespace std;

// ������������
Matrix::Matrix() : rows(0), cols(0) {}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.resize(rows, vector<double>(cols, 0.0));
}

Matrix::Matrix(const vector<vector<double>>& data) : rows(data.size()), cols(data[0].size()), data(data) {}

// ���������
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("��� �������� ������� ������ ����� ���������� �������.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] + other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator-(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("��� ��������� ������� ������ ����� ���������� �������.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] - other.data[i][j];
        }
    }
    return result;
}

Matrix Matrix::operator*(const Matrix& other) const {
    if (cols != other.rows) {
        throw invalid_argument("���������� �������� � ������ ������� ������ ���� ����� ���������� ����� �� ������ �������.");
    }
    Matrix result(rows, other.cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < other.cols; ++j) {
            for (int k = 0; k < cols; ++k) {
                result.data[i][j] += data[i][k] * other.data[k][j];
            }
        }
    }
    return result;
}

Matrix Matrix::operator*(double scalar) const {
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] * scalar;
        }
    }
    return result;
}

Matrix Matrix::operator/(double scalar) const {
    if (scalar == 0) {
        throw invalid_argument("������� �� ����.");
    }
    Matrix result(rows, cols);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[i][j] = data[i][j] / scalar;
        }
    }
    return result;
}

Matrix& Matrix::operator+=(const Matrix& other) {
    *this = *this + other;
    return *this;
}

Matrix& Matrix::operator-=(const Matrix& other) {
    *this = *this - other;
    return *this;
}

Matrix& Matrix::operator*=(const Matrix& other) {
    *this = *this * other;
    return *this;
}

Matrix& Matrix::operator*=(double scalar) {
    *this = *this * scalar;
    return *this;
}

Matrix& Matrix::operator/=(double scalar) {
    *this = *this / scalar;
    return *this;
}

bool Matrix::operator==(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != other.data[i][j]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::operator!=(const Matrix& other) const {
    return !(*this == other);
}

// ������ ��� ������ � ���������
Matrix Matrix::transpose() const {
    Matrix result(cols, rows);
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            result.data[j][i] = data[i][j];
        }
    }
    return result;
}

Matrix Matrix::inverse() const {
    if (!isSquare()) {
        throw invalid_argument("����� ����� �������� �������, ��� ������ ���� ����������.");
    }
    if (determinant() == 0) {
        throw invalid_argument("������� �������� ������������ � �� ����� ��������.");
    }
    // �����������, ��� ������� �������� � ����� ������ 2x2 ��� ��������.
    if (rows == 2) {
        double det = determinant();
        Matrix result(2, 2);
        result.data[0][0] = data[1][1] / det;
        result.data[0][1] = -data[0][1] / det;
        result.data[1][0] = -data[1][0] / det;
        result.data[1][1] = data[0][0] / det;
        return result;
    }
    throw invalid_argument("�������� �������������� ��� ������ �������� ����� 2x2 �� �����������.");
}

Matrix Matrix::pow(int exponent) const {
    if (!isSquare()) {
        throw invalid_argument("����� �������� ������� � �������, ��� ������ ���� ����������.");
    }
    if (exponent == 0) {
        return Matrix::identity(rows);
    }
    Matrix result = *this;
    for (int i = 1; i < exponent; ++i) {
        result *= *this;
    }
    return result;
}

double Matrix::determinant() const {
    if (!isSquare()) {
        throw invalid_argument("����� ����� ������������, ������� ������ ���� ����������.");
    }
    if (rows == 1) {
        return data[0][0];
    }
    if (rows == 2) {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }
    throw invalid_argument("������������ ��� ������ �������� ����� 2x2 �� ����������.");
}

double Matrix::norm() const {
    double sum = 0;
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            sum += data[i][j] * data[i][j];
        }
    }
    return sqrt(sum);
}

// ������ ��� �������� ���� �������
bool Matrix::isSquare() const {
    return rows == cols;
}

bool Matrix::isDiagonal() const {
    if (!isSquare()) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (i != j && data[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isZero() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isIdentity() const {
    if (!isSquare()) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if ((i == j && data[i][j] != 1) || (i != j && data[i][j] != 0)) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isSymmetric() const {
    if (!isSquare()) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            if (data[i][j] != data[j][i]) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isUpperTriangular() const {
    if (!isSquare()) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < i; ++j) {
            if (data[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

bool Matrix::isLowerTriangular() const {
    if (!isSquare()) {
        return false;
    }
    for (int i = 0; i < rows; ++i) {
        for (int j = i + 1; j < cols; ++j) {
            if (data[i][j] != 0) {
                return false;
            }
        }
    }
    return true;
}

// ������ ��� �����-������
void Matrix::input() {
    cout << "������� ���������� �����: ";
    cin >> rows;
    cout << "������� ���������� ��������: ";
    cin >> cols;
    data.resize(rows, vector<double>(cols));
    cout << "������� �������� ������� �� �������:\n";
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cin >> data[i][j];
        }
    }
}

void Matrix::print() const {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            cout << data[i][j] << " ";
        }
        cout << "\n";
    }
}

// ����������� ����� ��� �������� ��������� �������
Matrix Matrix::identity(int size) {
    Matrix result(size, size);
    for (int i = 0; i < size; ++i) {
        result.data[i][i] = 1.0;
    }
    return result;
}