#pragma once

#include <stdexcept>

template<typename T>
class Stack {

public:

    // Complejidad: O(1)
    Stack(int capacity)
    {
        _capacity = capacity;
        _data = new T[_capacity];
        _top = 0;
    }

    // Complejidad: O(1)
    ~Stack()
    {
        delete [] _data;
    }

    // Complejidad: O(1)
    void push(T value)
    {
        if (_top == _capacity) {
            throw std::overflow_error("Stack overflow!");
        }
        _data[_top] = value;
        ++_top;
    }

    // Complejidad: O(1)
    T pop()
    {
        if (_top == 0) {
            throw std::underflow_error("Stack underflow!");
        }
        --_top;
        return _data[_top];
    }

    // Complejidad: O(1)
    T peek() const
    {
        if (_top == 0) {
            throw std::underflow_error("Stack underflow!");
        }
        return _data[_top - 1];
    }

    // Complejidad: O(1)
    int size() const
    {
        return _top;
    }

    // Complejidad: O(1)
    int capacity() const
    {
        return _capacity;
    }

    // Complejidad: O(1)
    bool is_empty() const
    {
        return _top == 0;
    }

private:

    T* _data;
    int _capacity;
    int _top;
};
