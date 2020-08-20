#include "List.hpp"
#include <iostream>
using std::initializer_list;

#ifndef ArrayList_H
#define ArrayList_H

template <typename T>
class ArrayList : public List<T>
{
private:
    size_T _capacity;
    T *arr;

public:
    ArrayList();
    ArrayList(size_T capacity);
    ArrayList(const initializer_list<T> &list);
    ArrayList(const List<T> &list);
    ArrayList(const ArrayList<T> &list);

    virtual ~ArrayList();

    virtual T &operator[](size_T index) override;
    virtual T operator[](size_T index) const override;

    virtual bool insert(size_T index, T element) override;

    virtual T removeAt(size_T index) override;
    virtual bool remove(const T &element) override;

    size_T capacity() const;
};

#endif
