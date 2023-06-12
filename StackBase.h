#pragma once

#include <iostream>

#include "Sequence.h"

template <class T> class StackBase {
public:

    virtual T Front() const = 0;
    virtual T Pop() = 0;

    virtual int GetSize() const = 0;

    virtual bool IsEmpty() const = 0;

    virtual StackBase<T>* GetSubCol(int, int) const = 0;
    virtual StackBase<T>* Concatenation(StackBase<T>*) const = 0;
    virtual StackBase<T>* FindSubsequence(const StackBase<T>&) const = 0;

    virtual void Push(T) = 0;

    virtual void RemoveAt(int) = 0;
    virtual void Remove(T) = 0;
    virtual void InsertAt(T,int) = 0;

    virtual void Map(T(*func)(T)) = 0;

    virtual Sequence<T>* GetSequence() const = 0;

    virtual ~StackBase() {};
};