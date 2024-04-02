#ifndef lab_9
#define lab_9

#include <cstdio>

// Определение класса шаблона для шаблона структуры данных стека
template<class T>
class TStack {
protected:
    int numItem;
    T* item;
public:
    // Конструктор инициализирует стек, по умолчанию размером 10
    explicit TStack(size_t size = 10) {
        numItem = 0;
        item = new T[size];
    }
    // Деструктор освобождает память, используемую стеком
    ~TStack() {
        delete[] item;
    }
    void push(T t);// Функция для перемещения элемента в стек
    T pop();// Функция для извлечения и возврата верхнего элемента из стека
    T peek();// Функция для поиска и возврата верхнего элемента из стека без его удаления
    bool isEmpty() {// Функция для проверки того, пуст ли стек
        return numItem <= 0;
    }
};

template<class T> // Определение функции push
void TStack<T>::push(T t) {
    item[numItem++] = t;
}

template<class T> // Определение функции pop
T TStack<T>::pop() {
    return item[--numItem];
}

template<class T> // Определение функции peek
T TStack<T>::peek() {
    return item[numItem - 1];
}

#endif