#pragma once

#include <exception>
#include <string>

using namespace std;

class SetException : public exception {
public:
    SetException(const string& message) : message(message) {}
    const char* what() const noexcept override {
        return message.c_str();
    }
private:
    string message;
};

class ElementAlreadyExistsException : public SetException {
public:
    ElementAlreadyExistsException() : SetException("Ёлемент уже существует в наборе.") {}
};

class ElementNotFoundException : public SetException {
public:
    ElementNotFoundException() : SetException("Ёлемент не найден в наборе.") {}
};