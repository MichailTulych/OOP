#pragma once

template <typename T>
class DoublyLinkedList {
public:
    struct Node {
        T data;
        Node* prev;
        Node* next;
        Node(const T& data) : data(data), prev(nullptr), next(nullptr) {}
    };

    DoublyLinkedList() : head(nullptr), tail(nullptr), size(0) {}
    ~DoublyLinkedList() { clear(); }

    void push_back(const T& data) {
        Node* newNode = new Node(data);
        if (!head) {
            head = tail = newNode;
        }
        else {
            tail->next = newNode;
            newNode->prev = tail;
            tail = newNode;
        }
        size++;
    }

    void erase(Node* node) {
        if (!node) return;

        if (node->prev) node->prev->next = node->next;
        if (node->next) node->next->prev = node->prev;

        if (node == head) head = node->next;
        if (node == tail) tail = node->prev;

        delete node;
        size--;
    }

    Node* find(const T& data) const {
        Node* current = head;
        while (current) {
            if (current->data == data) return current;
            current = current->next;
        }
        return nullptr;
    }

    size_t getSize() const { return size; }

    void clear() {
        while (head) {
            Node* temp = head;
            head = head->next;
            delete temp;
        }
        tail = nullptr;
        size = 0;
    }

private:
    Node* head;
    Node* tail;
    size_t size;
};