#include "Matrix.h"
#include <cmath>
#include <stdexcept>
using namespace std;

// Конструкторы
Matrix::Matrix() : rows(0), cols(0) {}

Matrix::Matrix(int rows, int cols) : rows(rows), cols(cols) {
    data.resize(rows, vector<double>(cols, 0.0));
}

Matrix::Matrix(const vector<vector<double>>& data) : rows(data.size()), cols(data[0].size()), data(data) {}

// Операторы
Matrix Matrix::operator+(const Matrix& other) const {
    if (rows != other.rows || cols != other.cols) {
        throw invalid_argument("Для сложения матрицы должны иметь одинаковые размеры.");
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
        throw invalid_argument("Для вычитания матрицы должны иметь одинаковые размеры.");
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
        throw invalid_argument("Количество столбцов в первой матрице должно быть равно количеству строк во второй матрице.");
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
        throw invalid_argument("Деление на ноль.");
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

// Методы для работы с матрицами
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
        throw invalid_argument("Чтобы иметь обратную матрицу, она должна быть квадратной.");
    }
    if (determinant() == 0) {
        throw invalid_argument("Матрица является единственной и не имеет обратной.");
    }
    // Предполагаю, что матрица обратима и имеет размер 2x2 для простоты.
    if (rows == 2) {
        double det = determinant();
        Matrix result(2, 2);
        result.data[0][0] = data[1][1] / det;
        result.data[0][1] = -data[0][1] / det;
        result.data[1][0] = -data[1][0] / det;
        result.data[1][1] = data[0][0] / det;
        return result;
    }
    throw invalid_argument("Обратное преобразование для матриц размером более 2x2 не осуществимо.");
}

Matrix Matrix::pow(int exponent) const {
    if (!isSquare()) {
        throw invalid_argument("Чтобы возвести матрицу в степень, она должна быть квадратной.");
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
        throw invalid_argument("Чтобы иметь определитель, матрица должна быть квадратной.");
    }
    if (rows == 1) {
        return data[0][0];
    }
    if (rows == 2) {
        return data[0][0] * data[1][1] - data[0][1] * data[1][0];
    }
    throw invalid_argument("Определитель для матриц размером более 2x2 не существует.");
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

// Методы для проверки типа матрицы
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

// Методы для ввода-вывода
void Matrix::input() {
    cout << "Введите количество строк: ";
    cin >> rows;
    cout << "Введите количество столбцов: ";
    cin >> cols;
    data.resize(rows, vector<double>(cols));
    cout << "Введите элементы матрицы по строкам:\n";
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

// Статический метод для создания единичной матрицы
Matrix Matrix::identity(int size) {
    Matrix result(size, size);
    for (int i = 0; i < size; ++i) {
        result.data[i][i] = 1.0;
    }
    return result;
}