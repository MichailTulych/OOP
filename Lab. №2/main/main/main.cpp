#include "Factory.h"
#include <iostream>

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    Factory factory;
    int choice;

    do {
        cout << "\nМеню:\n"
            << "1. Создать объект\n"
            << "2. Удалить объект\n"
            << "3. Показать объекты\n"
            << "4. Переместить объект\n"
            << "5. Проверить пересечение\n"
            << "6. Выход\n"
            << "Выберите действие: ";
        cin >> choice;

        switch (choice) {
        case 1:
            factory.CreateObject();
            break;
        case 2:
            factory.DeleteObject();
            break;
        case 3:
            factory.ShowObjects();
            break;
        case 4:
            factory.MoveObject();
            break;
        case 5:
            factory.CheckIntersection();
            break;
        case 6:
            cout << "Выход из программы.\n";
            break;
        default:
            cout << "Неверный выбор.\n";
        }
    } while (choice != 6);

    return 0;
}
