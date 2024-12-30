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
    int birthDate[3]; // ����, �����, ���

public:
    // ����������� �� ���������
    ZNAK();

    // ������ ������� � �����
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

    // ���������� ��������� �������
    friend ostream& operator<<(ostream& os, const ZNAK& znak);

    // ���������� ��������� ����������
    friend istream& operator>>(istream& is, ZNAK& znak);

    // ���������� ��������� ��������� ��� ���������� �� ����� �������
    bool operator<(const ZNAK& other) const;
};