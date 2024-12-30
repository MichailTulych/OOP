#include "znak.h"
using namespace std;

// Конструктор по умолчанию
ZNAK::ZNAK() : surname(""), name(""), zodiacSign(ARIES), birthDate{ 0, 0, 0 } {}

// Методы доступа к полям
void ZNAK::setSurname(const string& s) { surname = s; }
void ZNAK::setName(const string& n) { name = n; }
void ZNAK::setZodiacSign(ZodiacSign z) { zodiacSign = z; }
void ZNAK::setBirthDate(int day, int month, int year) {
    birthDate[0] = day;
    birthDate[1] = month;
    birthDate[2] = year;
}

string ZNAK::getSurname() const { return surname; }
string ZNAK::getName() const { return name; }
ZodiacSign ZNAK::getZodiacSign() const { return zodiacSign; }
int ZNAK::getBirthDay() const { return birthDate[0]; }
int ZNAK::getBirthMonth() const { return birthDate[1]; }
int ZNAK::getBirthYear() const { return birthDate[2]; }

// Перегрузка оператора вставки
ostream& operator<<(ostream& os, const ZNAK& znak) {
    os << znak.surname << " " << znak.name << " " << znak.zodiacSign << " "
        << znak.birthDate[0] << "." << znak.birthDate[1] << "." << znak.birthDate[2];
    return os;
}

// Перегрузка оператора извлечения
istream& operator>>(istream& is, ZNAK& znak) {
    int zodiac;
    is >> znak.surname >> znak.name >> zodiac;
    znak.zodiacSign = static_cast<ZodiacSign>(zodiac);
    is >> znak.birthDate[0] >> znak.birthDate[1] >> znak.birthDate[2];
    return is;
}

// Перегрузка оператора сравнения для сортировки по знаку Зодиака
bool ZNAK::operator<(const ZNAK& other) const {
    return zodiacSign < other.zodiacSign;
}