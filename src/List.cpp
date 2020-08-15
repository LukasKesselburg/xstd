#include "List.hpp"
#include <iostream>

using std::cout;
using std::endl;
using std::string;
using std::ostream;


template <typename T>
bool List<T>::append(T element) {
    return this->insert(this->length(), element);
}

template<typename T>
ostream &operator<<(ostream &os, const List<T> &l) {
    os << "[";
    for (size_T i = 0; i < l->length() - 1; i++)
        os << l[i] << ",";
    os << l[l->length()] << "]";
    return os;
}


