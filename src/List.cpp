#include "List.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::ostream;

template <typename T>
List<T>::List() : _length(0) {}

template <typename T>
bool List<T>::append(T element)
{
    return this->insert(this->length(), element);
}

template <typename T>
void List<T>::checkIndexRange(size_T index) const
{
    if (index < 0 || this->_length <= index)
    {
        throw std::out_of_range("index out of range");
    }
}

template <typename T>
size_T List<T>::length() const
{
    return this->_length;
}

template <typename T>
ostream &operator<<(ostream &os, const List<T> &l)
{
    os << "[";
    if (l.length() > 0)
    {
        for (size_T i = 0; i < l.length() - 1; i++)
            os << l[i] << ", ";
        os << l[l.length() - 1];
    }
    os << "]";
    return os;
}
