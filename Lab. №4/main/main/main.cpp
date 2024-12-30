#include "znak.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip>
#include <fstream>
#include <Windows.h> // Для Windows

using namespace std;

void printMenu() {
    cout << "1 - Овен" << endl;
    cout << "2 - Телец" << endl;
    cout << "3 - Близнецы" << endl;
    cout << "4 - Рак" << endl;
    cout << "5 - Лев" << endl;
    cout << "6 - Дева" << endl;
    cout << "7 - Весы" << endl;
    cout << "8 - Скорпион" << endl;
    cout << "9 - Стрелец" << endl;
    cout << "10 - Козерог" << endl;
    cout << "11 - Водолей" << endl;
    cout << "12 - Рыбы" << endl;
}

int main() {
    // Установка кодировки консоли для Windows из-за проблем с руссским языком
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    printMenu();

    const int N = 1; // Количество людей
    vector<ZNAK> znaks(N);

    // Чтение данных из файла
    ifstream inputFile("data.txt");
    if (!inputFile) {
        cerr << "Ошибка открытия файла!" << endl;
        return 1;
    }

    for (int i = 0; i < N; ++i) {
        inputFile >> znaks[i];
    }

    // Сортировка по знаку Зодиака
    sort(znaks.begin(), znaks.end());

    // Ввод месяца для поиска
    int searchMonth;
    cout << "Введите месяц для поиска (числом): ";
    cin >> searchMonth;

    // Вывод информации о людях, родившихся в указанный месяц
    bool found = false;
    for (const auto& znak : znaks) {
        if (znak.getBirthMonth() == searchMonth) {
            cout << znak.getSurname() << " " << znak.getName() << " " << znak.getZodiacSign() << " "
                << setw(2) << setfill('0') << znak.getBirthDay() << "."
                << setw(2) << setfill('0') << znak.getBirthMonth() << "."
                << znak.getBirthYear() << endl;
            found = true;
        }
    }

    if (!found) {
        cout << "Нет людей, родившихся в этом месяце." << endl;
    }

    return 0;
}