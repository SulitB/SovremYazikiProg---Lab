#include <cstring>
#include <iostream>
#include "lab6.h"
#include <ostream>

using namespace std;

namespace stringNamespace {
    // Функция для вычисления длины строки
    static int length(const char* s1) {
        int i = 0;
        while (*s1++ != '\0')
            i++;
        return i;
    }
    // Функция для копирования одной строки в другую
    static void copy(char* s1, const char* s2) {
        size_t len = (strlen(s1) > strlen(s2)) ? strlen(s1) : strlen(s2);
        for (int i = 0; i <= len; i++)
            s1[i] = s2[i];
    }
    // Функция для сравнения двух строк
    static int compare(char* str1, char* str2) {
        int maxLength = min(length(str1), length(str2));
        for (int i = 0; i < maxLength; i++) {
            if (str1[i] != str2[i]) return -1;
        }
        return 0;
    }
    // Функция для объединения двух строк
    static void concat(char* str1, char* str2) {
        int size1 = length(str1);
        char* r = new char[size1 + length(str2)];
        int i = 0;
        for (; i < size1; i++)
            r[i] = str1[i];
        int j = 0;
        while (str2[j] != '\0') r[i++] = str2[j++];
        copy(str1, r);
    }

}

// Конструктор по символу
String::String(const char* s) {
    char* newStr = new char[stringNamespace::length(s)];
    str = newStr;
    stringNamespace::copy(str, s);
}
// Конструктор по строке
 String::String(const String& s) {
    char* newStr = new char[stringNamespace::length(s.str)];
    str = newStr;
    stringNamespace::copy(str, s.str);
}

// Переопределение оператора присваивания
 String& String::operator=(const String& s) {
    char* newStr = new char[stringNamespace::length(s.str)];
    str = newStr;
    stringNamespace::copy(str, s.str);
    return *this;
}
// Переопределение оператора конкатенации
 String& String::operator+(const String& s) {
    stringNamespace::concat(str, s.str);
    return *this;
}
// Переопределение оператора сравнения
 int String::operator==(const String& s) {
    return stringNamespace::compare(str, (char*)s.str) == 0;
}
// Функция для вычисления длины строки
 int String::length() {
    return stringNamespace::length(str);
}
// Функция для ввода строки
 void String::input() {
    cout << "Enter string: ";
    cin.getline(str, 50);
}
// Функция для вывода строки
 void String::output() {
    cout << str << endl;
}

// lab8
// Функция для переопределение оператора ввода
 istream& operator>>(istream& is, String& s) {
    char buff[1024];
    cin >> buff;
    s.str = new char[strlen(buff)];
    stringNamespace::copy(s.str, buff);
    return is;
}
// Функция для переопределение оператора вывода
 ostream& operator<<(ostream& os, String& s) {
    cout << s.str;
    return os;
}
