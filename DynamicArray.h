#pragma once

#include <iostream>

using namespace std;

template <class T>
class DynamicArray {
private:
    T* arr; // Указатель на массив элементов
    int size; // Текущий размер массива
    int capacity; // Емкость массива

public:
    // Конструктор по умолчанию
    DynamicArray() {
        arr = nullptr;
        size = 0;
        capacity = 0;
    }

    // Конструктор с передачей элементов из другого массива
    DynamicArray(T* items, int count) {
        arr = new T[count];
        size = count;
        capacity = count;
        for (int i = 0; i < count; i++) {
            arr[i] = items[i];
        }
    }

    // Конструктор с заданной емкостью
    DynamicArray(int initialCapacity) {
        arr = new T[initialCapacity];
        size = 0;
        capacity = initialCapacity;
    }

    // Копирующий конструктор
    DynamicArray(const DynamicArray<T> &dynamicArray) {
        size = dynamicArray.size;
        capacity = dynamicArray.capacity;
        arr = new T[capacity];
        for (int i = 0; i < size; i++) {
            arr[i] = dynamicArray.arr[i];
        }
    }

    T& operator[](int index) {
        if (index >= this->size || index < 0) {
            throw std::out_of_range("Index out of range");
        }
        return this->arr[index];
    }

    const T operator[](int index) const {
        return Get(index);
    }

    // Деструктор
    ~DynamicArray() {
        delete[] arr;
    }

    // Получить элемент по индексу
    T Get(int index) const {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        return arr[index];
    }

    // Получить размер массива
    int GetSize() {
        return size;
    }

    T GetFirst() const {
        return arr[0];
    }

    T GetLast() const  {
        return arr[size-1];
    }

    DynamicArray<T> *Substring(int startIndex, int endIndex) const {
        if (startIndex >= this->size || startIndex < 0) {
            throw std::out_of_range("Start index out of range");
        }

        if (endIndex >= this->size || endIndex < 0) {
            throw std::out_of_range("End index out of range");
        }

        if (startIndex > endIndex) {
            throw std::invalid_argument("Start index must be less than end index");
        }

        DynamicArray<T> *result = new DynamicArray<T>(endIndex - startIndex + 1);

        for (int i = startIndex; i <= endIndex; i++) {
            result->Append(this->arr[i]);
        }

        return result;
    }

    // Задать элемент по индексу
    void Set(int index, T value) {
        if (index < 0 || index >= size) {
            throw std::out_of_range("Index out of range");
        }
        arr[index] = value;
    }

    // Изменить размер массива
    void Resize(int newSize) {
        if (newSize < 0) {
            throw std::invalid_argument("Invalid size");
        }

        if (newSize == size) {
            return; // Размер не изменился
        }

        T* newArr = new T[newSize];
        int elementsToCopy = newSize < size ? newSize : size;

        for (int i = 0; i < elementsToCopy; i++) {
            newArr[i] = arr[i];
        }

        delete[] arr; // Освобождаем старую память

        arr = newArr;
        size = newSize;
        capacity = newSize;
    }

    void Append(T value) {
        if (size * 2 >= capacity) {
            capacity = (capacity == 0) ? 2 : capacity * 2;
            T *tmp = new T[capacity];

            for (int i = 0; i < size; i++) {
                tmp[i] = arr[i];
            }

            delete[] arr;
            arr = tmp;
        }

        arr[size] = value;
        size++;
    }

    void Prepend(T value) {
        if (size * 2 >= capacity) {
            capacity *= 2;
            T *tmp = new T[capacity];

            for (int i = 0; i < size; i++) {
                tmp[i] = arr[i];
            }

            delete[] arr;
            arr = tmp;
        }

        for (int i = size; i > 0; i--) {
            arr[i] = arr[i - 1];
        }

        arr[0] = value;
        this->size++;
    }


    void InsertAt(T value, int index) {
        // Проверка на допустимый индекс
        if (index < 0 || index > size) {
            throw std::out_of_range("Index out of range");
        }

        // Увеличение емкости массива, если необходимо
        if (size == capacity) {
            capacity *= 2;
            cout << "2" << endl;
            T *tmp = new T[capacity];
            cout << "2" << endl;

            for (int i = 0; i < size; i++) {
                tmp[i] = arr[i];
            }

            delete[] arr;
            arr = tmp;
        }

        // Сдвиг элементов вправо для освобождения места для нового элемента
        for (int i = size - 1; i >= index; i--) {
            arr[i + 1] = arr[i];
        }

        // Вставка нового элемента на заданный индекс
        arr[index] = value;

        // Увеличение размера массива
        size++;
    }

    void RemoveAt(int index) {
        if (index >= this->size || index < 0) {
            throw std::out_of_range("Index out of range");
        }

        for (int i = index; i < size - 1; i++) {
            arr[i] = arr[i + 1];
        }

        this->size--;
    }

    void Remove(T value) {
        for (int i = 0; i < size; i++) {
            if (arr[i] == value) {
                RemoveAt(i);
                i--;
            }
        }
    }

    int *begin() {
        return arr;
    }

    int *end() {
        return arr + size;
    }




};