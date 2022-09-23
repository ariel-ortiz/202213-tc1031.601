#pragma once

#include <iostream>
#include <sstream>
#include <stdexcept>

template<typename T>
class LinkedList {

public:

    // Prohibir inicialización
    LinkedList(const LinkedList& other) = delete;

    // Prohibir asignación
    LinkedList<T>& operator=(const LinkedList& other) = delete;

    // Complejidad: O(1)
    // Constructor por omisión (default)
    LinkedList()
    {
        _sentinel = new Node;
        _sentinel->next = _sentinel;
        _sentinel->prev = _sentinel;
    }

    // Complejidad: O(N)
    LinkedList(std::initializer_list<T> args): LinkedList()
    {
        for (T arg: args) {
            insert_back(arg);
        }
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
    void insert_back(T value)
    {
        Node* new_node = new Node;
        new_node->value = value;
        new_node->next = _sentinel;
        new_node->prev = _sentinel->prev;
        _sentinel->prev->next = new_node;
        _sentinel->prev = new_node;

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
        for (T value : *this) {
            if (first_time) {
                first_time = false;
            } else {
                result << ", ";
            }
            result << value;
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
        Node* p = _sentinel->next;
        T value = p->value;
        _sentinel->next = p->next;
        p->next->prev = _sentinel;
        delete p;
        --_size;
        return value;
    }

    // Complejidad: O(N), N = tamaño de other
    void extend(const LinkedList<T>& other)
    {
        for (T value : other) {
            insert_back(value);
        }
    }

private:

    struct Node {
        T value;
        Node* next;
        Node* prev;
    };

    class LinkedListIterator {

    public:

        // Complejidad: O(1)
        // Constructor
        LinkedListIterator(Node* current)
        {
            _current = current;
        }

        // Complejidad: O(1)
        // Dereference operator
        T operator*() const
        {
            return _current->value;
        }

        // Complejidad: O(1)
        // Pre-increment operator
        void operator++()
        {
            _current = _current->next;
        }

        // Complejidad: O(1)
        // Inequality operator
        bool operator!=(const LinkedListIterator& other) const
        {
            return _current != other._current;
        }

    private:

        Node* _current;
    };

    Node* _sentinel = nullptr;
    int _size = 0;

public:

    // “Pointer” to the start of the collection
    LinkedListIterator begin() const
    {
        return LinkedListIterator(_sentinel->next);
    }

    // “Pointer” to the end of the collection
    LinkedListIterator end() const
    {
        return LinkedListIterator(_sentinel);
    }
};

// Complejidad: O(N)
template<typename T>
std::ostream& operator<<(std::ostream& os, const LinkedList<T>& list)
{
    return os << list.to_string();
}
