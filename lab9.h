#ifndef lab_9
#define lab_9

#include <cstdio>

// ����������� ������ ������� ��� ������� ��������� ������ �����
template<class T>
class TStack {
protected:
    int numItem;
    T* item;
public:
    // ����������� �������������� ����, �� ��������� �������� 10
    explicit TStack(size_t size = 10) {
        numItem = 0;
        item = new T[size];
    }
    // ���������� ����������� ������, ������������ ������
    ~TStack() {
        delete[] item;
    }
    void push(T t);// ������� ��� ����������� �������� � ����
    T pop();// ������� ��� ���������� � �������� �������� �������� �� �����
    T peek();// ������� ��� ������ � �������� �������� �������� �� ����� ��� ��� ��������
    bool isEmpty() {// ������� ��� �������� ����, ���� �� ����
        return numItem <= 0;
    }
};

template<class T> // ����������� ������� push
void TStack<T>::push(T t) {
    item[numItem++] = t;
}

template<class T> // ����������� ������� pop
T TStack<T>::pop() {
    return item[--numItem];
}

template<class T> // ����������� ������� peek
T TStack<T>::peek() {
    return item[numItem - 1];
}

#endif