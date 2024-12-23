#pragma once

#include <list>
#include <algorithm>
#include "SetExceptions.h"
using namespace std;
template <typename T>
class Set {
public:
    // ���������� �������� � ���������
    void add(const T& element) {
        if (contains(element)) {
            throw ElementAlreadyExistsException();
        }
        elements.push_back(element);
    }

    // �������� �������� �� ���������
    void remove(const T& element) {
        auto it = find(elements.begin(), elements.end(), element);
        if (it == elements.end()) {
            throw ElementNotFoundException();
        }
        elements.erase(it);
    }

    // �������� ������� �������� � ���������
    bool contains(const T& element) const {
        return find(elements.begin(), elements.end(), element) != elements.end();
    }

    // ��������� ������� ���������
    size_t size() const {
        return elements.size();
    }

    // ������� ���������
    void clear() {
        elements.clear();
    }

private:
    list<T> elements;
};
