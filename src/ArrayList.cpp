#include "ArrayList.hpp"
#include <iostream>
#include <stdexcept>
#include <cstring>
using std::cout;
using std::endl;
using std::initializer_list;
using std::memcpy;
using std::ostream;
using std::string;

template <typename T>
ArrayList<T>::ArrayList() : List<T>(), _capacity(10)
{
    this->arr = new T[this->_capacity];
}

template <typename T>
ArrayList<T>::ArrayList(size_T capacity) : List<T>(), _capacity(capacity)
{
    this->arr = new T[this->_capacity];
}

template <typename T>
ArrayList<T>::ArrayList(const initializer_list<T> &list) : List<T>(), _capacity(2 * list.size())
{
    this->arr = new T[this->_capacity];
    for (auto &x : list)
    {
        this->arr[this->_length++] = x;
    }
}

template <typename T>
ArrayList<T>::ArrayList(const List<T> &list) : List<T>(), _capacity(2 * list.length())
{
    this->arr = new T[this->_capacity];
    for (;this->_length < list.length(); this->_length++)
    {
        this->arr[this->_length] = list[this->_length];
    }
}

template <typename T>
ArrayList<T>::ArrayList(const ArrayList<T> &list) : List<T>(), _capacity(list._capacity)
{
    this->arr = new T[this->_capacity];
    for (;this->_length < list.length(); this->_length++)
    {
        this->arr[this->_length] = list[this->_length];
    }
}

template <typename T>
ArrayList<T>::~ArrayList()
{
    delete[] this->arr;
}

template <typename T>
T &ArrayList<T>::operator[](size_T index)
{
    this->checkIndexRange(index);
    return this->arr[index];
}

template <typename T>
T ArrayList<T>::operator[](size_T index) const
{
    this->checkIndexRange(index);
    return this->arr[index];
}

template <typename T>
bool ArrayList<T>::insert(size_T index, T element)
{
    if (this->_length == this->_capacity)
    {
        this->_capacity = this->_capacity * 2;
        T *n = new T[this->_capacity];
        for (size_T i = 0; i < this->_length; i++)
        {
            n[i] = this->arr[i];
        }
        this->arr = n;
        // TODO: delete old array
    }

    this->_length++;
    this->checkIndexRange(index);
    for (size_T i = this->_length - 1; i > index; i--)
    {
        this->arr[i] = this->arr[i - 1];
    }
    this->arr[index] = element;
    return true;
}

template <typename T>
T ArrayList<T>::removeAt(size_T index)
{
    this->checkIndexRange(index);
    T res = this->arr[index];
    for (auto i = index; i < this->_length - 1; i++)
    // for (auto i = index; this->_length-->i; i++) // also comment line this->_length--;
    {
        this->arr[i] = this->arr[i + 1];
        // this->_length++;
    }
    this->_length--;
    return res;
}

template <typename T>
bool ArrayList<T>::remove(const T &element)
{
    for (size_t i = 0; i < this->_length; i++)
    {
        if (this->arr[i] == element)
        {
            this->removeAt(i);
            return true;
        }
    }
    return false;
}

template <typename T>
size_T ArrayList<T>::capacity() const
{
    return this->_capacity;
}

template <typename T>
ostream &operator<<(ostream &os, const ArrayList<T> &l)
{
    os << "[";
    if (0 < l.length())
    {
        for (size_T i = 0; i < l.length() - 1; i++)
            os << l[i] << ", ";
        os << l[l.length() - 1];
    }
    os << "]";
    return os;
}
