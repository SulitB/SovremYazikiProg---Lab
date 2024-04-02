#include <iostream> //подключение библиотеки iostream

int main(void) { // определение функции main
    setlocale(LC_ALL, "Russian");
    int i, k;//объ€вление переменных
    int power(int, int);//объ€вление функции
    for (i = 0; i < 10; i++) {//цикл от 0 до 9
        k = power(2, i); //приравнивание k значению фунцкии
        std::cout<< "i = " << i << ",k=" << k << std::endl; //вывод i и k
    }

    void exp02(); //выполнение задани€ 2
    exp02();

    void exp03();//выполнение задани€ 3
    exp03();
}
int power(int x, int n) {
    int i, p = 1;
    for (i = 1; i < n; i++)p *= x;//n-2 раза умножение p на x
    return p;//возвращение значени€ p
}