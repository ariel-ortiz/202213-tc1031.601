#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>

template<typename T>
class LinkedList {

public:

    // Complejidad: O(1)
    // Constructor por omisión (default)
    LinkedList()
    {
        _sentinel = new Node;
        _sentinel->next = _sentinel;
        _sentinel->prev = _sentinel;
    }

    // Complejidad: O(N)
    // Destructor
    ~LinkedList()
    {
        Node* current = _sentinel->next;

        while (current != _sentinel) {
            Node* p = current;
            current = current->next;
            delete p;
        }
        delete _sentinel;
    }

    // Complejidad: O(1)
    void insert_front(T value)
    {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = _sentinel->next;
        new_node->prev = _sentinel;
        _sentinel->next->prev = new_node;
        _sentinel->next = new_node;

        ++_size;
    }

    // Complejidad: O(1)
    int size() const
    {
        return _size;
    }

    // Complejidad: O(N)
    std::string to_string() const
    {
        std::ostringstream result;
        result << "[";

        bool first_time = true;
        Node* p = _start;
        while (p) {
            if (first_time) {
                first_time = false;
            } else {
                result << ", ";
            }
            result << p->value;
            p = p->next;
        }
        result << "]";
        return result.str();
    }

    // Complejidad: O(1)
    bool is_empty() const
    {
        return size() == 0;
    }

    // Complejidad: O(1)
    T remove_front()
    {
        if(is_empty()) {
            throw std::length_error(
                "Can't remove from the front of an empty list");
        }
        Node* p = _start;
        T value = _start->value;
        _start = _start->next;
        delete p;
        --_size;
        return value;
    }

private:

    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    Node* _sentinel = nullptr;
    int _size = 0;
};
