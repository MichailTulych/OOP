#pragma once

#include <list>
#include <algorithm>
#include "SetExceptions.h"
using namespace std;
template <typename T>
class Set {
public:
    // Добавление элемента в множество
    void add(const T& element) {
        if (contains(element)) {
            throw ElementAlreadyExistsException();
        }
        elements.push_back(element);
    }

    // Удаление элемента из множества
    void remove(const T& element) {
        auto it = find(elements.begin(), elements.end(), element);
        if (it == elements.end()) {
            throw ElementNotFoundException();
        }
        elements.erase(it);
    }

    // Проверка наличия элемента в множестве
    bool contains(const T& element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    // Получение размера множества
    size_t size() const {
        return elements.size();
    }

    // Очистка множества
    void clear() {
        elements.clear();
    }

private:
    list<T> elements;
};
