#include "Matrix.h"
#include <iostream>

using namespace std;

void printMenu() {
    cout << "1. Создать новые матрицы\n";
    cout << "2. Изменить матрицу A\n";
    cout << "3. Изменить матрицу B\n";
    cout << "4. Сложить две матрицы\n";
    cout << "5. Вычесть две матрицы\n";
    cout << "6. Умножить две матрицы\n";
    cout << "7. Умножить матрицу на скаляр\n";
    cout << "8. Разделить матрицу на скаляр\n";
    cout << "9. Транспонировать матрицу\n";
    cout << "10. Найти обратную матрицу\n";
    cout << "11. Возвести матрицу в степень\n";
    cout << "12. Вычислить определитель\n";
    cout << "13. Вычислить норму\n";
    cout << "14. Проверить, является ли матрица квадратной\n";
    cout << "15. Проверить, является ли матрица диагональной\n";
    cout << "16. Проверить, является ли матрица нулевой\n";
    cout << "17. Проверить, является ли матрица единичной\n";
    cout << "18. Проверить, является ли матрица симметричной\n";
    cout << "19. Проверить, является ли матрица верхней треугольной\n";
    cout << "20. Проверить, является ли матрица нижней треугольной\n";
    cout << "21. Выход\n";
    cout << "Введите ваш выбор: ";
}

void createNewMatrices(Matrix& A, Matrix& B) {
    cout << "Создание новых матриц A и B:\n";
    cout << "Введите матрицу A:\n";
    A.input();
    cout << "Введите матрицу B:\n";
    B.input();
}

void changeMatrix(Matrix& M) {
    cout << "Изменение матрицы:\n";
    M.input();
}

Matrix& selectMatrix(Matrix& A, Matrix& B) {
    int matrixChoice;
    cout << "Выберите матрицу (1 - A, 2 - B): ";
    cin >> matrixChoice;
    if (matrixChoice == 1) {
        return A;
    }
    else if (matrixChoice == 2) {
        return B;
    }
    else {
        cout << "Неверный выбор. По умолчанию будет использована матрица A.\n";
        return A;
    }
}

int main() {
    setlocale(LC_ALL, "Russian");
    Matrix A, B;
    int choice;
    double scalar;
    int exponent;

    while (true) {
        printMenu();
        cin >> choice;

        switch (choice) {
        case 1:
            createNewMatrices(A, B);
            break;
        case 2:
            changeMatrix(A);
            break;
        case 3:
            changeMatrix(B);
            break;
        case 4:
            cout << "Результат:\n";
            (A + B).print();
            break;
        case 5:
            cout << "Результат:\n";
            (A - B).print();
            break;
        case 6:
            cout << "Результат:\n";
            (A * B).print();
            break;
        case 7:
            cout << "Введите скаляр: ";
            cin >> scalar;
            cout << "Результат:\n";
            (selectMatrix(A, B) * scalar).print();
            break;
        case 8:
            cout << "Введите скаляр: ";
            cin >> scalar;
            cout << "Результат:\n";
            (selectMatrix(A, B) / scalar).print();
            break;
        case 9:
            cout << "Результат:\n";
            selectMatrix(A, B).transpose().print();
            break;
        case 10:
            cout << "Результат:\n";
            selectMatrix(A, B).inverse().print();
            break;
        case 11:
            cout << "Введите степень: ";
            cin >> exponent;
            cout << "Результат:\n";
            selectMatrix(A, B).pow(exponent).print();
            break;
        case 12:
            cout << "Определитель: " << selectMatrix(A, B).determinant() << "\n";
            break;
        case 13:
            cout << "Норма: " << selectMatrix(A, B).norm() << "\n";
            break;
        case 14:
            cout << "Является квадратной: " << (selectMatrix(A, B).isSquare() ? "Да" : "Нет") << "\n";
            break;
        case 15:
            cout << "Является диагональной: " << (selectMatrix(A, B).isDiagonal() ? "Да" : "Нет") << "\n";
            break;
        case 16:
            cout << "Является нулевой: " << (selectMatrix(A, B).isZero() ? "Да" : "Нет") << "\n";
            break;
        case 17:
            cout << "Является единичной: " << (selectMatrix(A, B).isIdentity() ? "Да" : "Нет") << "\n";
            break;
        case 18:
            cout << "Является симметричной: " << (selectMatrix(A, B).isSymmetric() ? "Да" : "Нет") << "\n";
            break;
        case 19:
            cout << "Является верхней треугольной: " << (selectMatrix(A, B).isUpperTriangular() ? "Да" : "Нет") << "\n";
            break;
        case 20:
            cout << "Является нижней треугольной: " << (selectMatrix(A, B).isLowerTriangular() ? "Да" : "Нет") << "\n";
            break;
        case 21:
            return 0;
        default:
            cout << "Неверный выбор. Пожалуйста, попробуйте снова.\n";
        }
    }
}