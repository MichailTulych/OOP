#include "znak.h"
#include <vector>
#include <algorithm>
#include <iostream>
#include <iomanip> 
#include <Windows.h> // Для Windows

using namespace std;

int main() {
    // Установка кодировки консоли для Windows из-за проблем с руссским языком
    SetConsoleCP(1251);
    SetConsoleOutputCP(1251);

    const int N = 1; // Количество людей
    vector<ZNAK> znaks(N);

    // Ввод данных с клавиатуры
    cout << "Введите данные для " << N << " людей:" << endl;
    for (int i = 0; i < N; ++i) {
        string surname, name, zodiacSign;
        int day, month, year;

        cout << "Введите фамилию: ";
        cin >> surname;
        cout << "Введите имя: ";
        cin >> name;
        cout << "Введите знак Зодиака: ";
        cin >> zodiacSign;
        cout << "Введите день рождения: ";
        cin >> day;
        cout << "Введите месяц рождения (числом): ";
        cin >> month;
        cout << "Введите год рождения: ";
        cin >> year;

        znaks[i].setSurname(surname);
        znaks[i].setName(name);
        znaks[i].setZodiacSign(zodiacSign);
        znaks[i].setBirthDate(day, month, year);
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