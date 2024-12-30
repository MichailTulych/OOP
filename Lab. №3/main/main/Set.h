#pragma once

#include "DoublyLinkedList.h"
#include "SetExceptions.h"

template <typename T>
class Set {
public:
    void add(const T& element) {
        if (contains(element)) {
            throw ElementAlreadyExistsException();
        }
        elements.push_back(element);
    }

    void remove(const T& element) {
        auto node = elements.find(element);
        if (!node) {
            throw ElementNotFoundException();
        }
        elements.erase(node);
    }

    bool contains(const T& element) const {
        return elements.find(element) != nullptr;
    }

    size_t size() const {
        return elements.getSize();
    }

    void clear() {
        elements.clear();
    }

private:
    DoublyLinkedList<T> elements;
};