#pragma once

#include <functional>
#include <initializer_list>
#include <queue>
#include <cmath>

template<typename T>
class TreeSet {

public:

    // Complejidad: O(1)
    TreeSet() {}

    // Complejidad: O(N log N)
    TreeSet(std::initializer_list<T> args)
    {
        for (T value : args) {
            add(value);
        }
    }

    // Complejidad: O(N)
    ~TreeSet()
    {
        _delete(_root);
    }

    // Complejidad: O(log N)
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

    // Complejidad: O(1)
    int size() const
    {
        return _size;
    }

    // Complejidad: O(1)
    bool is_empty() const
    {
        return _size == 0;
    }

    // Complejidad: O(log N)
    bool contains(T value) const
    {
        return _contains(value, _root);
    }

    // Complejidad: O(N)
    void inorder(std::function<void(T)> fn) const
    {
        _inorder(fn, _root);
    }

    // Complejidad: O(N)
    void preorder(std::function<void(T)> fn) const
    {
        _preorder(fn, _root);
    }

    // Complejidad: O(N)
    void postorder(std::function<void(T)> fn) const
    {
        _postorder(fn, _root);
    }

    // Complejidad: O(N)
    void levelorder(std::function<void(T)> fn) const
    {
        std::queue<Node*> queue;
        queue.push(_root);
        while (not queue.empty()) {
            Node* p = queue.front();
            queue.pop();
            if (p) {
                fn(p->value);
                queue.push(p->left);
                queue.push(p->right);
            }
        }
    }

    // Complejidad: O(N)
    int height() const
    {
        return _height(_root);
    }

    // Complejidad: O(N)
    bool is_full() const
    {
        return _is_full(_root);
    }

    // Complejidad: O(N)
    int leaf_count() const
    {
        return _leaf_count(_root);
    }

    // Complejidad: O(N)
    bool is_perfect() const
    {
        return static_cast<int>(std::pow(2, height() + 1)) - 1 == size();
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

    void _delete(Node* p)
    {
        if (p) {
            _delete(p->left);
            _delete(p->right);
            delete p;
        }
    }

    void _inorder(std::function<void(T)> fn, Node* p) const
    {
        if (p) {
            _inorder(fn, p->left);
            fn(p->value);
            _inorder(fn, p->right);
        }
    }

    void _preorder(std::function<void(T)> fn, Node* p) const
    {
        if (p) {
            fn(p->value);
            _preorder(fn, p->left);
            _preorder(fn, p->right);
        }
    }

    void _postorder(std::function<void(T)> fn, Node* p) const
    {
        if (p) {
            _postorder(fn, p->left);
            _postorder(fn, p->right);
            fn(p->value);
        }
    }

    bool _contains(T value, Node* p) const
    {
        if (p) {
            if (p->value == value) {
                return true;
            } else if (value < p->value) {
                return _contains(value, p->left);
            } else {
                return _contains(value, p->right);
            }
        } else {
            return false;
        }
    }

    int _height(Node* p) const
    {
        if (p) {
            return 1 + std::max(_height(p->left), _height(p->right));
        } else {
            return -1;
        }
    }

    bool _is_full(Node* p) const
    {
        if (p) {
            if (not p->left and not p->right) {
                return true;
            } else if (p->left and p->right) {
                return _is_full(p->left) and _is_full(p->right);
            } else {
                return false;
            }
        } else {
            return true;
        }
    }

    int _leaf_count(Node* p) const
    {
        if (p) {
            if (not p->left and not p->right) {
                return 1;
            } else {
                return _leaf_count(p->left) + _leaf_count(p->right);
            }
        } else {
            return 0;
        }
    }

    Node* _root = nullptr;
    int _size = 0;
};
