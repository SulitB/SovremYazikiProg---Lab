#include <cstdio>
#include <iostream>
#include <fstream>

using namespace std;


int main() {
    // Открытие файла lab8.txt и перемещение указателя в конец файла
    ofstream ofs("lab8.txt", ios::in | ios::ate);
    // Проверка, успешно ли открыт файл
    if (!ofs) {
        printf("file not opened");
        return -1;
    }

    char chars[] = { '\n', 'a', 'b', 'c' };
    // Записываем массив символов в конец файла
    for (char ch : chars) {
        ofs.put(ch);
    }

    return 0;
}