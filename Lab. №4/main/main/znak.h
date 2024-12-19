#pragma once

#include <string>
#include <iostream>
using namespace std;
class ZNAK {
private:
    string surname;
    string name;
    string zodiacSign;
    int birthDate[3]; // день, месяц, год

public:
    // Конструктор по умолчанию
    ZNAK();

    // Методы доступа к полям
    void setSurname(const string& s);
    void setName(const string& n);
    void setZodiacSign(const string& z);
    void setBirthDate(int day, int month, int year);

    string getSurname() const;
    string getName() const;
    string getZodiacSign() const;
    int getBirthDay() const;
    int getBirthMonth() const;
    int getBirthYear() const;

    // Перегрузка оператора вставки
    friend ostream& operator<<(ostream& os, const ZNAK& znak);

    // Перегрузка оператора извлечения
    friend istream& operator>>(istream& is, ZNAK& znak);

    // Перегрузка оператора сравнения для сортировки по знаку Зодиака
    bool operator<(const ZNAK& other) const;
};
