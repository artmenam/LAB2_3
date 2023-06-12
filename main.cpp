#include <iostream>
#include <tuple>

#include "StackBase.h"
#include "Stack.h"
#include "Sequence.h"
#include "test.h"

using namespace std;

template<typename T>
void printStack(StackBase<T> *collection) {
    Sequence<T> *sequence = collection->GetSequence();
    cout << "[";
    for (int i = 0; i < collection->GetSize(); i++) {
        cout << sequence->Get(i) << (i + 1 == sequence->GetSize() ? "" : ", ");
    }
    cout << "]";
    cout << endl;
}

void printMenu() {
    cout << "1. Front" << endl;
    cout << "2. Pop" << endl;
    cout << "3. GetSize" << endl;
    cout << "4. GetSubCol" << endl;
    cout << "5. Concatenation" << endl;
    cout << "6. Push" << endl;
    cout << "7. RemoveAt" << endl;
    cout << "8. Remove" << endl;
    cout << "9. InsertAt" << endl;
    cout << "10. Map(multiply by 2)" << endl;
    cout << "11. Print stack" << endl;
    cout << "12. Find substack" << endl;
    cout << "0. Exit" << endl;
    cout << "Enter your choice: ";
}

template <typename T>
void menu() {
    StackBase<T> *stack, *stack2, *concatStack;

    bool exitMenu = false;

    int choice, choiceMenu, index;

    T value;

    cout << "Choose sequence type:" << endl;
    cout << "1. Stack" << endl;
    cout << "2. AutoTest" << endl;
    cin >> choice;

    switch (choice) {
        case 1:
            stack = new Stack<T>();
            break;
        case 2:
            test();
            cout << "Success";
            return;
    }

    StackBase<T>* subStack = nullptr;

    while(!exitMenu) {
        printMenu();
        std:cin >> choiceMenu;
        switch (choiceMenu) {
            case 1:
                cout << "First element: ";
                cout << stack->Front() << endl;
                break;
            case 2:
                stack->Pop();
                cout << "Stack after pop: ";
                printStack(stack);
                break;
            case 3:
                cout << "Size: ";
                cout << stack->GetSize() << endl;
                break;
            case 4:
                cout << "Enter start index: ";
                cin >> index;
                cout << "Enter end index: ";
                cin >> value;
                subStack = stack->GetSubCol(index, value);
                cout << "SubStack: ";
                printStack(subStack);
                delete subStack;
                break;
            case 5:
                stack2 = new Stack<T>;
                cout << "Enter values to append second stack (enter -1 to stop): " << endl;
                while (true) {
                    cin >> value;
                    if (value == -1) {
                        break;
                    }
                    stack2->Push(value);
                }
                concatStack = stack->Concatenation(stack2);
                cout << "Concatenation stack: ";
                printStack(concatStack);
                delete stack2;
                delete concatStack;
                break;
            case 6:
                cout << "Enter value to push: ";
                cin >> value;
                stack->Push(value);
                cout << "Stack after push: ";
                printStack(stack);
                break;
            case 7:
                cout << "Enter index to remove at: ";
                cin >> index;
                stack->RemoveAt(index);
                cout << "Stack after remove at: ";
                printStack(stack);
                break;
            case 8:
                cout << "Enter value to remove: ";
                cin >> value;
                stack->Remove(value);
                cout << "Stack after remove: ";
                printStack(stack);
                break;
            case 9:
                cout << "Enter index to insert at: ";
                cin >> index;
                cout << "Enter value to insert: ";
                cin >> value;
                stack->InsertAt(value, index);
                cout << "Stack after insert: ";
                printStack(stack);
                break;
            case 10:
                stack->Map([](T value) { return value * 2; });
                cout << "Stack after map: ";
                printStack(stack);
                break;
            case 11:
                cout << "Current stack: ";
                printStack(stack);
                break;

            case 12:
                stack2 = new Stack<T>;
                cout << "Enter values to append subStack (enter -1 to stop): " << endl;
                while (true) {
                    cin >> value;
                    if (value == -1) {
                        break;
                    }
                    stack2->Push(value);
                }
                if (stack->FindSubsequence(*stack2) == nullptr) {
                    cout << "SubStack not found." << endl;
                } else {
                    cout << "SubStack found" << endl;
                }
                printStack(stack);
                delete stack2;
                break;
            case 0:
                exitMenu = true;
                break;
            default:
                cout << "Invalid choice. Please try again." << endl;
        }
    }

}

int main() {
    menu<int>();
    return 0;
}
