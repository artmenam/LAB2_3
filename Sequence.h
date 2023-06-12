#pragma once

#include <tuple>


template <class T> class Sequence {

public:

    virtual T Get(int) const = 0;
    virtual T GetFirst() const = 0;
    virtual T GetLast() const = 0;

    virtual int GetSize() const = 0;

    virtual Sequence<T>* Substring(int, int) const = 0;
    virtual Sequence<T>* Concatenation(Sequence<T>*) const = 0;

    virtual void Append(T) = 0;
    virtual void Prepend(T) = 0;
    virtual void InsertAt(T, int) = 0;
    virtual void RemoveAt(int) = 0;
    virtual void Remove(T) = 0;


    virtual void Map(T(func)(T)) = 0;

    virtual T& operator[](int) = 0;
    virtual T operator[](int) const = 0;

    virtual ~Sequence() {};

};
