#include "DoubleLinkedList.hpp"

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList() : List<T>()
{
    this->_start = new DNode<T>(0);
    this->_end = new DNode<T>(0, this->_start, nullptr);
    this->_start->_next = this->_end;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const initializer_list<T> &list) : DoubleLinkedList<T>()
{
    this->_length = list.size();

    DNode<T> *prev = this->_start;

    for (auto &x : list)
    {
        prev = new DNode<T>(x, prev, nullptr);
        prev->_prev->_next = prev;
    }

    this->_end->_prev = prev;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const List<T> &list) : DoubleLinkedList<T>()
{
    this->_length = list.length();

    DNode<T> *prev = this->_start;

    for (size_T i = 0; i < this->_length; i++)
    {
        prev = new DNode<T>(list[i], prev, nullptr);
        prev->_prev->_next = prev;
    }

    this->_end->_prev = prev;
}

template <typename T>
DoubleLinkedList<T>::DoubleLinkedList(const DoubleLinkedList<T> &list) : DoubleLinkedList<T>()
{
    this->_length = list.length();

    DNode<T> *prev = this->_start;

    for (DNode<T> *cur = list->_start->_next; cur != nullptr; cur = cur->_next)
    {
        prev = new DNode<T>(cur->value, prev, nullptr);
        prev->_prev->_next = prev;
    }

    this->_end = prev;
}

template <typename T>
DoubleLinkedList<T>::~DoubleLinkedList()
{
    while (this->_start != this->_end)
    {
        this->_start = this->_start->_next;
        delete this->_start->_prev;
    }
    delete this->_end;
}

template <typename T>
T &DoubleLinkedList<T>::operator[](size_T index)
{
    this->checkIndexRange(index);

    DNode<T> *cur = this->_start->_next;
    for (; 0 < index; index--)
    {
        cur = cur->_next;
    }
    return cur->value;
}

template <typename T>
T DoubleLinkedList<T>::operator[](size_T index) const
{
    this->checkIndexRange(index);

    DNode<T> *cur = this->_start->_next;
    for (; 0 < index; index--)
    {
        cur = cur->_next;
    }
    return cur->value;
}

template <typename T>
bool DoubleLinkedList<T>::insert(size_T index, T element)
{
    this->_length++;
    this->checkIndexRange(index);

    DNode<T> *prev = this->_start;
    for (; 0 < index; index--)
    {
        prev = prev->_next;
    }
    prev->_next = new DNode<T>(element, prev, prev->_next);
    prev->_next->_next->_prev = prev->_next;

    return true;
}

template <typename T>
T DoubleLinkedList<T>::removeAt(size_T index)
{
    this->checkIndexRange(index);
    this->_length--;

    DNode<T> *cur = this->_start->_next;
    for (; 0 < index; index--)
    {
        cur = cur->_next;
    }

    cur->_prev->_next = cur->_next;
    cur->_next->_prev = cur->_prev;
    T res = cur->value;
    delete cur;

    return res;
}

template <typename T>
bool DoubleLinkedList<T>::remove(const T &element)
{
    DNode<T> *cur = this->_start->_next;
    while (cur->value != element && cur->_next != this->_end)
    {
        cur = cur->_next;
    }

    if (cur->value != element)
    {
        return false;
    }

    cur->_prev->_next = cur->_next;
    cur->_next->_prev = cur->_prev;
    delete cur;
    this->_length--;

    return true;
}