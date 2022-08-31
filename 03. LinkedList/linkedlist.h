#pragma once

template<typename T>
class LinkedList {

public:

    // Complejidad: O(1)
    // Constructor por omisión (default)
    LinkedList()
    {

    }

private:

    struct Node {
        T value;
        Node* next;
    };

    Node* _start = nullptr;
    int _size = 0;
};
