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

    Stack<T>* FindSubsequence(const StackBase<T>& subsequence) const override{
        Stack<T>* result = new Stack<T>();

        int subIndex = 0;
        int stackIndex = 0;
        int subSize = subsequence.GetSize();
        int stackSize = this->GetSize();

        while (stackIndex < stackSize) {
            if (this->sequence->Get(stackIndex) == subsequence.GetSequence()->Get(subIndex)) {
                subIndex++;
                stackIndex++;

                if (subIndex == subSize) {
                    int startIndex = stackIndex - subSize;
                    int endIndex = stackIndex - 1;

                    for (int i = startIndex; i <= endIndex; i++) {
                        result->Push(this->sequence->Get(i));
                    }

                    return result;
                }
            }
            else {
                subIndex = 0;
                stackIndex++;
            }
        }

        delete result;
        return nullptr;
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