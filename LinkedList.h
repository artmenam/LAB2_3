#pragma once

#include <iostream>

using namespace std;

// Шаблонный класс LinkedList
template <class T>
class LinkedList {
private:
    // Внутренний класс узла списка
    class Node {
    public:
        T data;
        Node* next;

        Node(const T& item) : data(item), next(nullptr) {}

        T operator*() {
            return this->item;
        }
    };

    Node* head; // Указатель на голову списка
    int size;   // Размер списка

public:
    // Создание объекта LinkedList из переданного массива
    LinkedList(T* items, int count) {
        if (count <= 0) {
            throw std::invalid_argument("Invalid count");
        }

        head = nullptr;
        size = 0;

        // Копирование элементов из массива
        for (int i = 0; i < count; i++) {
            Append(items[i]);
        }
    }

    // Создание пустого списка
    LinkedList() : head(nullptr), size(0) {}

    // Копирующий конструктор
    LinkedList(const LinkedList<T>& list) : head(nullptr), size(0) {
        Node* current = list.head;

        // Копирование элементов из существующего списка
        while (current != nullptr) {
            Append(current->data);
            current = current->next;
        }
    }

    // Получение первого элемента списка
    T GetFirst() const {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        return head->data;
    }

    // Получение последнего элемента списка
    T GetLast() const {
        if (head == nullptr) {
            throw std::out_of_range("List is empty");
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }

        return current->data;
    }

    // Получение элемента по индексу
    T Get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }

        Node* current = head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }

        return current->data;
    }

    // Метод для нахождения подсписка по индексам
    LinkedList<T> *Substring(int startIndex, int endIndex) const {
        if (startIndex < 0 ||  endIndex >= this->size || startIndex > endIndex) {
            throw std::out_of_range("Index out of range");
        }
        LinkedList<T>* result = new LinkedList<T>();
        Node *current = this->head;
        for (int i = 0; i < startIndex; i++) {
            current = current->next;
        }
        for (int i = startIndex; i <= endIndex; i++) {
            result->Append(current->data);
            current = current->next;
        }
        return result;
    }

    void deleteLinkedList(Node* head) {
        while (head != nullptr) {
            Node* current = head;
            head = head->next;
            delete current;
        }
    }

    int GetSize() const {
        return this->size;
    }

    // Добавление элемента в конец списка
    void Append(T item) {
        Node* newNode = new Node(item);

        if (head == nullptr) {
            head = newNode;
        } else {
            Node* current = head;
            while (current->next != nullptr) {
                current = current->next;
            }

            current->next = newNode;
        }

        this->size++;
    }

    // Добавление элемента в начало списка
    void Prepend(T item) {
        Node* newNode = new Node(item);

        newNode->next = this->head;
        this->head = newNode;

        this->size++;
    }

    // Вставка элемента в заданную позицию списка
    void InsertAt(T item, int index) {
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0) {
            Prepend(item);
        } else if (index == size) {
            Append(item);
        } else {
            Node* newNode = new Node(item);
            Node* current = head;

            for (int i = 0; i < index - 1; i++) {
                current = current->next;
            }

            newNode->next = current->next;
            current->next = newNode;

            this->size++;
        }
    }

    T& operator[](int index) {
        return this->GetLinkedListItem(index);
    }

    const T operator[](int index) const {
        return this->Get(index);
    }

    ~LinkedList() {
        Node* current = head;
        while (current != nullptr) {
            Node* next = current->next;
            delete current;
            current = next;
        }
        head = nullptr;
        size = 0;
    }

    // Метод для получения указателя на первый элемент списка
    T* begin() const {
        if (head == nullptr) {
            return nullptr;  // Возвращаем nullptr, если список пуст
        }
        return &(head->data);
    }

    // Метод для получения указателя на последний элемент списка
    T* end() const {
        if (head == nullptr) {
            return nullptr;  // Возвращаем nullptr, если список пуст
        }
        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        return &(current->data);
    }

    void RemoveAt(int index) {
        if (index < 0 || index >= this->size) {
            throw std::out_of_range("Index out of range");
        }

        if (index == 0) {
            // Удаляем голову списка
            Node* current = this->head;
            this->head = this->head->next;
            delete current;
        } else {
            Node* current = this->head;
            Node* previous = nullptr;

            // Доходим до элемента, который нужно удалить
            for (int i = 0; i < index; i++) {
                previous = current;
                current = current->next;
            }

            previous->next = current->next;
            delete current;
        }

        this->size--;
    }

    void Remove(T data) {
        Node* current = this->head;
        int index = 0;
        while (current != nullptr) {
            if (current->data == data) {
                this->RemoveAt(index);
                return;
            }
            current = current->next;
            index++;
        }
        throw std::invalid_argument("Not found");
    }

    LinkedList<T> *Concatenation(const LinkedList<T> &input_list) const {
        LinkedList<T> *res = new LinkedList<T>(*this);
        for (auto i : input_list) {
            res->Append(i);
        }
        return res;
    }

protected:
    T& GetLinkedListItem(int index) {
        Node *current = this->head;
        for (int i = 0; i < index; i++) {
            current = current->next;
        }
        return current->data;
    }
};