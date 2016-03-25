#ifndef CORE_ARRAY_H
#define CORE_ARRAY_H

// Generic dynamically-allocated array.
template <class T>
class Array {
public:
    // Constructs an array of specific size.
    Array(unsigned size);

    // Deconstructs an array.
    ~Array();

    // Copies an external array.
    T& operator=(const T &other);

    // Moves an external array.
    T& operator=(T &&other);

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
Array<T>::~Array() {
    if (_data != nullptr) {
        delete []_data;
    }
}

template <class T>
T& Array<T>::operator=(const T &other) {
    if (this != &other) {
        delete []_data;
        _data = new T[other._size];
        for (unsigned i = 0; i < other._size; i++) {
            _data[i] = other._data[i];
        }
        _size = other._size;
    }
    return this;
}

template <class T>
T& Array<T>::operator=(T &&other) {
    if (this != &other) {
        delete []_data;
        _data = other._data;
        other._data = nullptr;
        _size = other._size;
    }
    return this;
}

template <class T>
unsigned Array<T>::size() const {
    return _size;
}

template <class T>
T& Array<T>::operator[](const unsigned &i) const {
    return _data[i];
}

#endif
