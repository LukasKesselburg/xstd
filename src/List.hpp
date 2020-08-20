// #pragma once

#ifndef List_H
#define List_H

typedef unsigned long long size_T;

template <typename T>
class List
{
protected:
    size_T _length;
    void checkIndexRange(size_T index) const;

public:
    List();

    // virtual ~List();

    virtual T &operator[](size_T index) = 0;
    virtual T operator[](size_T index) const = 0;

    virtual bool append(T element);
    virtual bool insert(size_T index, T element) = 0;

    virtual T removeAt(size_T index) = 0;
    virtual bool remove(const T &element) = 0;

    virtual size_T length() const;
};

#endif
