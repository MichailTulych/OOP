#include <iostream>
#include <string>
#include "Set.h"

using namespace std;

int main() {
    setlocale(LC_ALL, "Russian");
    try {
        // Инстанцирование для типа int
        Set<int> intSet;
        intSet.add(1);
        intSet.add(2);
        intSet.add(3);

        // Попытка добавить уже существующий элемент
        try {
            intSet.add(2);
        }
        catch (const ElementAlreadyExistsException& e) {
            cerr << "Исключение: " << e.what() << endl;
        }

        // Удаление элемента
        intSet.remove(2);

        // Попытка удалить несуществующий элемент
        try {
            intSet.remove(2);
        }
        catch (const ElementNotFoundException& e) {
            cerr << "Исключение: " << e.what() << endl;
        }

        // Инстанцирование для типа double
        Set<double> doubleSet;
        doubleSet.add(1.1);
        doubleSet.add(2.2);
        doubleSet.add(3.3);

        // Попытка добавить уже существующий элемент
        try {
            doubleSet.add(2.2);
        }
        catch (const ElementAlreadyExistsException& e) {
            cerr << "Исключение: " << e.what() << endl;
        }

        // Удаление элемента
        doubleSet.remove(2.2);

        // Попытка удалить несуществующий элемент
        try {
            doubleSet.remove(2.2);
        }
        catch (const ElementNotFoundException& e) {
            cerr << "Исключение: " << e.what() << endl;
        }

        // Инстанцирование для типа string
        Set<string> stringSet;
        stringSet.add("Один");
        stringSet.add("Два");
        stringSet.add("Три");

        // Попытка добавить уже существующий элемент
        try {
            stringSet.add("Два");
        }
        catch (const ElementAlreadyExistsException& e) {
            cerr << "Исключение: " << e.what() << endl;
        }

        // Удаление элемента
        stringSet.remove("Два");

        // Попытка удалить несуществующий элемент
        try {
            stringSet.remove("Два");
        }
        catch (const ElementNotFoundException& e) {
            cerr << "Исключение: " << e.what() << endl;
        }

    }
    catch (const SetException& e) {
        cerr << "Исключение: " << e.what() << endl;
    }

    return 0;
}