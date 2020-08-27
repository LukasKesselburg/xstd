#include "LinkedList.hpp"

template <typename T>
LinkedList<T>::LinkedList() : List<T>(), _start(nullptr) {}

template <typename T>
LinkedList<T>::LinkedList(const initializer_list<T> &list) : List<T>(), _start(nullptr)
{
    this->_length = list.size();

    this->_start = new Node<T>(0, nullptr);
    Node<T> *cur = this->_start;

    for (auto &x : list)
    {
        cur->_next = new Node<T>(x, nullptr);
        cur = cur->_next;
    }

    this->_start = this->_start->_next;
}

template <typename T>
LinkedList<T>::LinkedList(const List<T> &list) : List<T>(), _start(nullptr)
{
    this->_length = list.length();

    this->_start = new Node<T>(0, nullptr);
    Node<T> *cur = this->_start;

    for (size_T i = 0; i < this->_length; i++)
    {
        cur->_next = new Node<T>(list[i], nullptr);
        cur = cur->_next;
    }

    this->_start = this->_start->_next;
}

template <typename T>
LinkedList<T>::LinkedList(const LinkedList<T> &list) : List<T>(), _start(nullptr)
{
    this->_length = list.length();

    if (list._length > 0)
    {
        Node<T> *it = list->_start;
        this->_start = new Node<T>(it->value, nullptr);
        Node<T> *cur = this->_start;

        while (it->_next != nullptr)
        {
            it = it->_next;
            cur->_next = new Node<T>(it->value, nullptr);
        }
    }
}

template <typename T>
LinkedList<T>::~LinkedList()
{
}

template <typename T>
T &LinkedList<T>::operator[](size_T index)
{
    this->checkIndexRange(index);

    Node<T> *cur = this->_start;
    for (; 0 < index; index--)
    {
        cur = cur->_next;
    }
    return cur->value;
}

template <typename T>
T LinkedList<T>::operator[](size_T index) const
{
    this->checkIndexRange(index);

    Node<T> *cur = this->_start;
    for (; 0 < index; index--)
    {
        cur = cur->_next;
    }
    return cur->value;
}

template <typename T>
bool LinkedList<T>::insert(size_T index, T element)
{
    this->_length++;
    this->checkIndexRange(index);

    if (index == 0)
    {
        this->_start = new Node<T>(element, this->length() == 1 ? nullptr : this->_start);
    }
    else
    {
        Node<T> *cur = this->_start;
        for (; 1 < index; index--)
        {
            cur = cur->_next;
        }
        cur->_next = new Node<T>(element, cur->_next);
    }

    return true;
}

template <typename T>
T LinkedList<T>::removeAt(size_T index)
{
    this->checkIndexRange(index);
    this->_length--;

    Node<T> *cur = this->_start, *prev = nullptr;
    for (size_T i = 0; i < index; i++)
    {
        prev = cur;
        cur = cur->_next;
    }
    Node<T> res = *cur, *next = cur->_next;
    delete cur;
    if (index == 0)
    {
        this->_start = next;
    }
    else
    {
        prev->_next = next;
    }

    return res.value;
}

template <typename T>
bool LinkedList<T>::remove(const T &element)
{
    Node<T> *prev, *cur;
    for (cur = this->_start; cur->value != element && cur->_next != nullptr; cur = cur->_next)
    {
        prev = cur;
    }

    if (cur->value != element)
    {
        return false;
    }
    prev->_next = cur->_next;
    delete cur;
    this->_length--;
    return true;
}