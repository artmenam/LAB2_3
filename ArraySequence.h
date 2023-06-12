#pragma once

#include "DynamicArray.h"
#include "Sequence.h"

template <class T> class ArraySequence: public Sequence<T> {

    DynamicArray<T> *buffer;

public:
    ArraySequence() : buffer(new DynamicArray<T>()) {};

    ArraySequence(T items, int count) : buffer(new DynamicArray<T>(items, count)) {};

    ArraySequence(const DynamicArray<T> &input_array) : buffer(new DynamicArray<T>(input_array)) {};

    ArraySequence(const ArraySequence<T> &input_array) : buffer(new DynamicArray<T>(*input_array.buffer)) {};

    ArraySequence(Sequence<T> *input_sequence) : buffer(new DynamicArray<T>()) {
        for (int i = 0; i < input_sequence->GetSize(); i++) {
            this->buffer->Append(input_sequence->Get(i));
        }
    };

    T Get (int index) const override {
        return this->buffer->Get(index);
    }

    T GetFirst() const override {
        return this->buffer->GetFirst();
    }

    T GetLast() const override {
        return this->buffer->GetLast();
    }

    ArraySequence<T> *Substring(int startIndex, int endIndex) const override {
        DynamicArray<T> *tmp = this->buffer->Substring(startIndex,endIndex);
        ArraySequence<T>* res = new ArraySequence(*tmp);
        delete tmp;
        return res;
    }

    int GetSize() const override {
        return this->buffer->GetSize();
    }

    void Append(T item) override {
        this->buffer->Append(item);
    }

    void Prepend(T item) override {
        this->buffer->Prepend(item);
    }

    void InsertAt(T item, int index) override {
        this->buffer->InsertAt(item, index);
    }

    void Resize(int newSize)  {
        this->buffer->Resize(newSize);
    }

    void Set(int index, T value)  {
        this->buffer->Set(index, value);
    }

    void RemoveAt(int index) override {
        this->buffer->RemoveAt();
    }

    void Remove(T value) override {
        this->buffer->Remove(value);
    }

    T& operator[](int index) override {
        return (*this->buffer)[index];
    }

    T operator[](int index) const override {
        return (*this->buffer)[index];
    }

    void Map(T(*func)(T)) override {
        for (int i = 0; i < GetSize(); i++) {
            (*this->buffer)[i] = func(this->buffer->Get(i));
        }
    }


    int *begin() {
        return this->buffer->begin();
    }

    int *end() {
        return this->buffer->end();
    }

    ~ArraySequence() {
        delete this->buffer;
    }
};