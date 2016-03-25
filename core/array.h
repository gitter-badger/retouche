#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

#include <stdexcept>
#include <cstring>

// Generic dynamically-allocated array.
template <class T>
class Array {
public:
    // Constructs an array of specific size.
    Array(unsigned size);

    // Copies array data.
    Array(const Array<T> &that);

    // Moves array data.
    Array(Array<T> &&that);

    // Deconstructs an array.
    ~Array();

    // Assigns array data.
    Array<T>& operator=(Array<T> that);

    // Accesses the element of an array at a specific index.
    T& operator[](const unsigned &i) const;

    // Returns the size of an array.
    unsigned size() const;

private:
    T *_data;
    unsigned _size;
};

template <class T>
Array<T>::Array(unsigned size): _size(size) {
    _data = new T[size];
}

template <class T>
Array<T>::Array(const Array<T> &that): _size(that._size) {
    _data = new T[_size];
    std::memcpy(_data, that._data, _size);
}

template <class T>
Array<T>::Array(Array<T> &&that): _size(that._size) {
    _data = that._data;
    that._data = nullptr;
}

template <class T>
Array<T>::~Array() {
    if (_data != nullptr) {
        delete []_data;
    }
}

template <class T>
Array<T>& Array<T>::operator=(Array<T> that) {
    _size = that._size;
    std::swap(_data, that._data);
    return *this;
}

template <class T>
unsigned Array<T>::size() const {
    return _size;
}

template <class T>
T& Array<T>::operator[](const unsigned &i) const {
    if (i >= _size) {
        throw std::invalid_argument("index out of bounds");
    }

    return _data[i];
}

#endif
