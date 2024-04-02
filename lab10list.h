#ifndef LIST
#define LIST

#include <cstdio>
// Определение шаблона структуры Node
template<class T>
struct Node {
    int key{};
    T data;
    Node* next = nullptr;
};
// Определение шаблона структуры LinkedList
template<class T>
struct LinkedList {
    Node<T>* start = nullptr;
    Node<T>* end = nullptr;

public:
    void add(int key, T data);// Функция для добавления нового узла в связанный список
    void first(int key, T data);// Функция для добавления первого узла в связанный список
    Node<T>* find(int key);// Функция для поиска узла в связанном списке
    Node<T>* findPrev(int key);// Функция для поиска предыдущего узла
    Node<T>* remove(int key);// Функция для удаления узла из связанного списка
};

//---------------------------------------------------
 
template<class T> // Определение функции добавления первого
void LinkedList<T>::first(int key, T data) {
    start = new Node<T>;
    start->key = key;
    start->data = data;
    start->next = nullptr;
    end = start;
}

template<class T> // Определение функции добавления
void LinkedList<T>::add(int key, T data) {
    if (start == nullptr) {
        first(key, data);
        return;
    }

    auto* n = new Node<T>;
    n->key = key;
    n->data = data;

    if (&start == &end) {
        start->next = n;
        n->next = end;
    }
    else {
        end->next = n;
        end = n;
    }
}

template<class T> // Определение функции поиска предыдущего
Node<T>* LinkedList<T>::findPrev(int key) {
    Node<T>* prev = start;
    Node<T>* cur = start;
    do {
        if (cur->key == key) {
            return prev;
        }
        prev = cur;
        cur = cur->next;
    } while (cur->next != nullptr);
    return nullptr;
}

template<class T> // Определение функции поиска
Node<T>* LinkedList<T>::find(int key) {
    Node<T>* cur = start;
    while (cur->key != key) {
        cur = cur->next;
    }
    return cur;
}

template<class T> // Определение функции удаления
Node<T>* LinkedList<T>::remove(int key) {
    Node<T>* prev = findPrev(key);
    Node<T>* cur = find(key);
    if (cur == start) {
        start = nullptr;
        return cur;
    }
    prev->next = cur->next;
    return cur;
}

#endif