#include "List.hpp"
#include <iostream>
using std::initializer_list;

#ifndef ArrayList_H
#define ArrayList_H

template <typename T>
class ArrayList : public List<T>
{
private:
    size_T _length;
    size_T _capacity;
    T* arr;

    void checkIndexRange(size_T index) const;
public:
    ArrayList();
    ArrayList(size_T capacity);
    ArrayList(const initializer_list<T>& list);
    // ArrayList(List<T>& list);
    ArrayList(const ArrayList<T>& list);

    virtual ~ArrayList();

    virtual T &operator[](size_T index) override;
    virtual T operator[](size_T index) const override;

    virtual bool insert(size_T index, T element) override;

    virtual T removeAt(size_T index) override;
    virtual bool remove(const T &element) override;

    virtual size_T length() const override;

    size_T capacity() const;
};


// template <typename T>
// class ArrayList<T, 10> {};


// template <typename T, int DIM>                              // (A)
// struct vector_special {
//     static const size_t dim = DIM;
//     T data[dim];
    
//     T operator[](int i) const { return data[i]; }
//     T& operator[](int i) { return data[i]; }
    
//     template <typename S>                                   // (B)
//     vector_special& operator=(const vector_special<S,DIM> & v) {
//         for (size_t i=0; i<dim; ++i)
//             data[i] = (T)(v.data[i]);                       // (C)
//         return *this;
//     }
// };

// template <typename T>                                       // (D)
// struct vector_special<T,0> {
//     static const size_t dim = 0;
//     T data;
    
//     T operator[](int) const { return data; }
//     T& operator[](int) { return data; }
// };


#endif
