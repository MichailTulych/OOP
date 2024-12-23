#pragma once

#include <string>
#include <iostream>
using namespace std;
class ZNAK {
private:
    string surname;
    string name;
    string zodiacSign;
    int birthDate[3]; // ����, �����, ���

public:
    // ����������� �� ���������
    ZNAK();

    // ������ ������� � �����
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

    // ���������� ��������� �������
    friend ostream& operator<<(ostream& os, const ZNAK& znak);

    // ���������� ��������� ����������
    friend istream& operator>>(istream& is, ZNAK& znak);

    // ���������� ��������� ��������� ��� ���������� �� ����� �������
    bool operator<(const ZNAK& other) const;
};
