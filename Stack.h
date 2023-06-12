#pragma once

#include <iostream>

#include "StackBase.h"
#include "ListSequence.h"

using namespace std;

template <typename T>
class Stack : public StackBase<T> {
private:
    ListSequence<T> *sequence;
public:
    Stack() {
        this->sequence = new ListSequence<T>();
    }

    Stack(const StackBase<T>& collection) {
        this->sequence = new ListSequence<T>(collection.GetSequence());
    }

    //возвращает значение первого элемента(посл доб)
    T Front() const override {
        if (IsEmpty()) {
            throw out_of_range("Stack is empty");
        }
        return this->sequence->GetLast();
    }

    //извлекает первый элемент(посл добав) и удаляет
    T Pop() override {
        if (IsEmpty()) {
            throw out_of_range("Stack is empty");
        }
        T item = this->sequence->GetLast();
        this->sequence->RemoveAt(this->sequence->GetSize() - 1);
        return item;
    }

    Stack<T>* GetSubCol(int startIndex, int endIndex) const override {
        Stack<T>* sub = new Stack<T>(*this);
        sub->sequence = sub->sequence->Substring(startIndex, endIndex);
        return sub;
    }

    Stack<T>* Concatenation(StackBase<T>* Collection) const override {
        Stack<T>* res = new Stack<T>(*this);
        res->sequence = res->sequence->Concatenation(Collection->GetSequence());
        return res;
    }

    int GetSize() const override {
        return this->sequence->GetSize();
    }

    bool IsEmpty() const override {
        return this->sequence->GetSize() == 0;
    };

    //добавляет в конец элемент
    void Push(T item) override {
        this->sequence->Append(item);
    }

    void Map(T(*func)(T)) override {
        this->sequence->Map(func);
    }

    void RemoveAt(int index) override{
        this->sequence->RemoveAt(index);
    }

    void Remove(T value) override {
        this->sequence->Remove(value);
    }

    void InsertAt(T item, int index) override {
        this->sequence->InsertAt(item,index);
    }


    Sequence<T>* GetSequence() const override {
        return this->sequence;
    }

    ~Stack() {
        delete this->sequence;
    }

};