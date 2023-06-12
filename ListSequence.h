#pragma once


#include "LinkedList.h"
#include "Sequence.h"


template <class T> class ListSequence: public Sequence<T> {

    LinkedList<T> *buffer;

public:
    ListSequence(T* items, int count) : buffer(new LinkedList<T>(items, count)) {};

    ListSequence(const LinkedList<T>& list) : buffer(new LinkedList<T>(list)) {};

    ListSequence() : buffer(new LinkedList<T>()) {};

    ListSequence(const ListSequence<T> &input_list) : buffer(new LinkedList<T>(*input_list.buffer)) {};


    T GetFirst() const override {
        return this->buffer->GetFirst();
    }

    T GetLast() const override {
        return this->buffer->GetLast();
    }

    T Get(int index) const override {
        return this->buffer->Get(index);
    }

    ListSequence<T> *Substring(int startIndex, int endIndex) const override {
        LinkedList<T> *tmp = this->buffer->Substring(startIndex,endIndex);
        ListSequence<T>* res = new ListSequence<T>(*tmp);
        delete tmp;
        return res;
    }

    ListSequence<T> *Concatenation(Sequence<T> *list) const override {
        ListSequence<T>* res = new ListSequence<T>(*this);
        for (int i = 0; i < list->GetSize(); i++) {
            res->Append(list->Get(i));
        }
        return res;
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

    void RemoveAt(int index) override {
        this->buffer->RemoveAt(index);
    }

    void Remove(T item) override {
        this->buffer->Remove(item);
    }

    int GetSize() const override {
        return this->buffer->GetSize();
    }

    T& operator[](int index) override {
        return (*this->buffer)[index];
    }

    T operator[](int index) const override {
        return this->buffer->Get(index);
    }

    void Map(T (*func)(T)) override {
        for (int i = 0; i < this->GetSize(); i++) {
            (*this->buffer)[i] = func(this->buffer->Get(i));
        }
    }


    T *begin() {
        return this->buffer->begin();
    }

    T *end() {
        return this->buffer->end();
    }

    ~ListSequence() {
        delete this->buffer;
    }



};
