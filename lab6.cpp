#include <iostream>
#include "lab6-1.cpp"

using namespace std;

int main() {
    String s1("test"), s3, s4(s1), s5;

    //Ввод строки в s3 и её вывод
    s3.input();
    s3.output();

    //Вывод длины s5 и его содержания
    cout << "s5.length = " << s5.length() << ", ";
    s5.output();

    //Сравнение s1 с s5 и s4
    if (s1 == s5) {
        cout << "s1 == s5";
    }
    else if (s1 == s4) {
        cout << "s1 == s4";
    }

    return 0;
}