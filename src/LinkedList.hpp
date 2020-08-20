#include "List.hpp"
#include <iostream>
using std::initializer_list;

#ifndef LinkedList_H
#define LinkedList_H

template <typename T>
class Node;

template <typename T>
class LinkedList : public List<T>
{
private:
    Node<T> *_start;

public:
    LinkedList();
    LinkedList(const initializer_list<T> &list);
    LinkedList(const List<T> &list);
    LinkedList(const LinkedList<T> &list);

    virtual ~LinkedList();

    virtual T &operator[](size_T index) override;
    virtual T operator[](size_T index) const override;

    virtual bool insert(size_T index, T element) override;

    virtual T removeAt(size_T index) override;
    virtual bool remove(const T &element) override;
};

template <typename T>
class Node
{
public:
    T value;

private:
    Node *_next;

    Node(const T &value, Node *next) : value(value), _next(next){};

    friend class LinkedList<T>;
};

#endif
