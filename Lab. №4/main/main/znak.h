#pragma once

#include <string>
#include <iostream>
using namespace std;

enum ZodiacSign {
    ARIES = 1, TAURUS, GEMINI, CANCER, LEO, VIRGO, LIBRA, SCORPIO, SAGITTARIUS, CAPRICORN, AQUARIUS, PISCES
};

class ZNAK {
private:
    string surname;
    string name;
    ZodiacSign zodiacSign;
    int birthDate[3]; // день, месяц, год

public:
    // Конструктор по умолчанию
    ZNAK();

    // Методы доступа к полям
    void setSurname(const string& s);
    void setName(const string& n);
    void setZodiacSign(ZodiacSign z);
    void setBirthDate(int day, int month, int year);

    string getSurname() const;
    string getName() const;
    ZodiacSign getZodiacSign() const;
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