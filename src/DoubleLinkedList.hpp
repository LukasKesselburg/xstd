#include "List.hpp"
#include <iostream>
using std::initializer_list;

#ifndef DoubleLinkedList_H
#define DoubleLinkedList_H

template <typename T>
class DNode;

template <typename T>
class DoubleLinkedList : public List<T>
{
private:
    DNode<T> *_start, *_end;

public:
    DoubleLinkedList();
    DoubleLinkedList(const initializer_list<T> &list);
    DoubleLinkedList(const List<T> &list);
    DoubleLinkedList(const DoubleLinkedList<T> &list);

    virtual ~DoubleLinkedList();

    virtual T &operator[](size_T index) override;
    virtual T operator[](size_T index) const override;

    virtual bool insert(size_T index, T element) override;

    virtual T removeAt(size_T index) override;
    virtual bool remove(const T &element) override;
};

template <typename T>
class DNode
{
public:
    T value;

private:
    DNode *_prev, *_next;

    DNode(const T &value) : value(value), _prev(nullptr), _next(nullptr) {};
    DNode(const T &value, DNode *prev, DNode *next) : value(value), _prev(prev), _next(next) {};

    friend class DoubleLinkedList<T>;
};

#endif
