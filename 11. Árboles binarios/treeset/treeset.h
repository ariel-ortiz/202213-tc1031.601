#pragma once

#include <functional>
#include <initializer_list>
#include <queue>

template<typename T>
class TreeSet {

public:

    TreeSet() {}

    bool add(T value)
    {
        if (_root) {
            Node* p = _root;
            while (true) {
                if (value == p->value) {
                    return false;
                } else if (value < p->value) {
                    if (p->left) {
                        p = p->left;
                    } else {
                        p->left = new Node(value);
                        ++_size;
                        return true;
                    }
                } else {
                     if (p->right) {
                        p = p->right;
                    } else {
                        p->right = new Node(value);
                        ++_size;
                        return true;
                    }
                }
            }
        } else {
            _root = new Node(value);
            ++_size;
            return true;
        }
    }


private:

    struct Node {
        Node(T value)
        {
            this->value = value;
        }
        T value;
        Node* left = nullptr;
        Node* right = nullptr;
    };

    Node* _root = nullptr;
    int _size = 0;
};
