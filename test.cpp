#include <iostream>
#include <cassert>

#include "StackBase.h"
#include "Stack.h"

using namespace std;


int pow2(int n) {
    return n * n;
}
template <typename StackBase>
void TestIsEmpty(StackBase& collection) {
    assert(collection.IsEmpty());
    collection.Push(1);
    assert(!collection.IsEmpty());

}

template <typename StackBase>
void TestGetSize(StackBase& collection) {

    assert(collection.GetSize() == 0);
    collection.Push(1);
    assert(collection.GetSize() == 1);
    collection.Push(2);
    assert(collection.GetSize() == 2);

}

template <typename T>
void TestFrontS(Stack<T>& collection) {

    collection.Push(1);
    for (int i = 0; i < 10; i++) {
        collection.Push(i);
        assert(collection.Front() == i);
    }

}template <typename T>
void TestPopS(Stack<T>& collection) {

    for (int i = 0; i < 10; i++) {
        collection.Push(i);
    }
    for (int i = 9; i >= 0; i--) {
        assert(collection.Pop() == i);
    }
    assert(collection.IsEmpty());

}template <typename T>
void TestMapS(Stack<T>& collection) {

    for (int i = 0; i < 10; i++) {
        collection.Push(i);
    }
    collection.Map(pow2);
    for (int i = 9; i >= 0; i--) {
        assert(collection.Pop() == i * i);
    }

}

template <typename StackBase>
void TestGetSubCollection(StackBase& collection) {

    for (int i = 0; i < 10; i++) {
        collection.Push(i);
    }
    StackBase* sub = collection.GetSubCol(0, 5);
    assert(sub->GetSize() == 6);
    delete sub;

}

template <typename StackBase>
void TestConcat(StackBase& collection1, StackBase& collection2) {

    for (int i = 0; i < 10; i++) {
        collection1.Push(i);
    }
    for (int i = 10; i < 20; i++) {
        collection2.Push(i);
    }
    StackBase* collection3 = collection1.Concatenation(&collection2);
    assert(collection3->GetSize() == 20);
    delete collection3;

}
void test () {
    Stack<int> *stack = nullptr;  stack = new Stack<int>();    TestIsEmpty(*stack);    delete stack;
    stack = new Stack<int>();    TestGetSize(*stack);    delete stack;
    stack = new Stack<int>();    TestFrontS(*stack);    delete stack;
    stack = new Stack<int>();    TestPopS(*stack);    delete stack;
    stack = new Stack<int>();    TestMapS(*stack);    delete stack;
    stack = new Stack<int>();    TestGetSubCollection(*stack);    delete stack;
    stack = new Stack<int>();    Stack<int> *stack2 = new Stack<int>();    TestConcat(*stack, *stack2);
    delete stack;
    delete stack2;
}