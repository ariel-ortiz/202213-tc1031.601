#pragma once

#include <iostream>
#include <sstream>

template<typename T>
class LinkedList {

public:

    // Complejidad: O(1)
    // Constructor por omisión (default)
    LinkedList()
    {

    }

    // Complejidad: O(N)
    // Destructor
    ~LinkedList()
    {
        Node* current = _start;

        while (current) {
            Node* p = current;
            current = current->next;
            delete p;
        }
    }

    // Complejidad: O(1)
    void insert_front(T value)
    {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = _start;
        _start = new_node;
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

private:

    struct Node {
        T value;
        Node* next;
    };

    Node* _start = nullptr;
    int _size = 0;
};
