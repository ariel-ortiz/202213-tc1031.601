#include "intlist.h"
#include "recursion.h"

// Complejidad: O(N)
int size(const IntList& a)
{
    if (is_empty(a)) {
        return 0;
    } else {
        return 1 + size(rest(a));
    }
}

// Complejidad: O(N)
IntList cons_end(int value, const IntList& a)
{
    if (is_empty(a)) {
        return cons(value, a);
    } else {
        return cons(first(a), cons_end(value, rest(a)));
    }
}

// Complejidad: O(N)
int sum(const IntList& a)
{
    if (is_empty(a)) {
        return 0;
    } else {
        return first(a) + sum(rest(a));
    }
}

// Complejidad: O(N)
IntList duplicate(const IntList& a)
{
    if (is_empty(a)) {
        return IntList {};
    } else {
        return cons(first(a), cons(first(a), duplicate(rest(a))));
    }
}

// Complejidad: O(N)
int last(const IntList& a)
{
    if (is_empty(rest(a))) {
        return first(a);
    } else {
        return last(rest(a));
    }
}

// Complejidad: O(N)
IntList but_last(const IntList& a)
{
    if (is_empty(rest(a))) {
        return IntList {};
    } else {
        return cons(first(a), but_last(rest(a)));
    }
}

// Complejidad: O(N)
int maximum(const IntList& a)
{
    if (is_empty(rest(a))) {
        return first(a);
    } else {
        return std::max(first(a), maximum(rest(a)));
    }
}

// Complejidad: O(N), donde N es el tamaño de a
IntList append(const IntList& a, const IntList& b)
{
    if (is_empty(a)) {
        return b;
    } else {
        return cons(first(a), append(rest(a), b));
    }
}

// Complejidad: O(N)
IntList repeat(int n, int value)
{
    if (n == 0) {
        return IntList {};
    } else {
        return cons(value, repeat(n - 1, value));
    }
}

IntList reverse(const IntList& a)
{
    return IntList {};
}

// Complejidad: O(N + M), donde N es el tamaño de a y M es el tamaño de b
//              O(N) donde N es la suma de los tamaños de a y b
IntList merge(const IntList& a, const IntList& b)
{
    if (is_empty(a)) {
        return b;
    } else if (is_empty(b)) {
        return a;
    } else if (first(a) < first(b)) {
        return cons(first(a), merge(rest(a), b));
    } else {
        return cons(first(b), merge(a, rest(b)));
    }
}

bool is_prefix(const IntList& a, const IntList& b)
{
    return false;
}

// Complejidad: O(N)
IntList insert(int value, const IntList& a)
{
    if (is_empty(a)) {
        return IntList {value};
    } else if (value <= first(a)) {
        return cons(value, a);
    } else {
        return cons(first(a), insert(value, rest(a)));
    }
}

// Complejidad: O(N^2)
IntList insertion_sort(const IntList& a)
{
    if (is_empty(a)) {
        return IntList {};
    } else {
        return insert(first(a), insertion_sort(rest(a)));
    }
}

IntList binary(int n)
{
    return IntList {};
}
