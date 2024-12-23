#include "znak.h"
using namespace std;
// ����������� �� ���������
ZNAK::ZNAK() : surname(""), name(""), zodiacSign(""), birthDate{ 0, 0, 0 } {}

// ������ ������� � �����
void ZNAK::setSurname(const string& s) { surname = s; }
void ZNAK::setName(const string& n) { name = n; }
void ZNAK::setZodiacSign(const string& z) { zodiacSign = z; }
void ZNAK::setBirthDate(int day, int month, int year) {
    birthDate[0] = day;
    birthDate[1] = month;
    birthDate[2] = year;
}

string ZNAK::getSurname() const { return surname; }
string ZNAK::getName() const { return name; }
string ZNAK::getZodiacSign() const { return zodiacSign; }
int ZNAK::getBirthDay() const { return birthDate[0]; }
int ZNAK::getBirthMonth() const { return birthDate[1]; }
int ZNAK::getBirthYear() const { return birthDate[2]; }

// ���������� ��������� �������
ostream& operator<<(ostream& os, const ZNAK& znak) {
    os << znak.surname << " " << znak.name << " " << znak.zodiacSign << " "
        << znak.birthDate[0] << "." << znak.birthDate[1] << "." << znak.birthDate[2];
    return os;
}

// ���������� ��������� ����������
istream& operator>>(istream& is, ZNAK& znak) {
    is >> znak.surname >> znak.name >> znak.zodiacSign;
    is >> znak.birthDate[0] >> znak.birthDate[1] >> znak.birthDate[2];
    return is;
}

// ���������� ��������� ��������� ��� ���������� �� ����� �������
bool ZNAK::operator<(const ZNAK& other) const {
    return zodiacSign < other.zodiacSign;
}