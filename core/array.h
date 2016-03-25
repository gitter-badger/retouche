#ifndef SIZED_ARRAY_H
#define SIZED_ARRAY_H

template <class T>
class Array {
public:
    Array(unsigned size);
    ~Array();
    T& operator=(const T &other);
    T& operator=(T &&other);

    T& operator[](const unsigned &i) const;

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
