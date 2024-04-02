#define _CRT_SECURE_NO_WARNINGS
#include <cstring>
#include <iostream>
#include <cstdio>
#include <fstream>
#include <sstream>

using namespace std;

// Подсчет видимых и невидимых символов
void visibleInvisible(FILE* in) {
    char ch;
    int visible = 0, invisible = 0;
    while (!feof(in)) { //по символьный просмотр файла
        ch = getc(in);
        if ((int)ch <= 32) { //прибавление к невидимым символам если код по таблице ASCII меньше 33
            invisible++;
        }
        else {      //иначе прибавление к видимым
            visible++;
        }
    }
    cout << "Visible = " << visible << "\nInvisible = " << invisible << endl;
    fclose(in);
}

// Поиск подстроки в файле с выводом тех строк, в которых она найдена
void findSubstring(FILE* in, char* s) {
    if (in == nullptr) {
        printf("Input file not opened");
        return;
    }

    char buff[1024];
    char* line;
    FILE* out;

    if ((out = fopen("5result.txt", "w")) == nullptr) { //проверка файла для результата
        printf("Output file not opened");
        return;
    }

    bool found = false;
    while ((line = fgets(buff, sizeof buff, in))) {
        if (strstr(line, s) != nullptr) {
            found = true;
            char const* c1 = "Found at line: ";
            char* r = new char[strlen(c1) + strlen(line) + 1];
            strcpy(r, c1); //копирование строки
            strcat(r, line); // добавление к строке
            fputs(r, out); // запись в файл результата
        }
    }

    if (!found) { //сообщение ошибки если нет совпадений
        printf("Substring not found in the file");
    }

    fclose(out);//закрытие файла с результатом
}

// Функция переноса страниц
void processPages(const char* filename) {
    ifstream file(filename);
    string line;
    string content;
    int pageNumber;

    if (!file.is_open()) {
        cerr << "Unable to open file: " << filename << endl;
        return;
    }

    ofstream outFile("5output.txt");
    if (!outFile.is_open()) {
        cerr << "Unable to create processed file." << endl;
        return;
    }

    while (getline(file, line)) {
        if (!line.empty() && isdigit(line[0])) {
            if (!content.empty()) {
                // Записать содержимое и номер страницы в выходной файл
                outFile << content << pageNumber << endl;
                content.clear();
            }
            istringstream iss(line);
            iss >> pageNumber;
        }
        else {
            content += line + "\n";
        }
    }

    // Запишите последнее содержимое и номер страницы в выходной файл
    if (!content.empty()) {
        outFile << content << pageNumber << endl;
    }

    file.close();
    outFile.close();

    cout << "File processed successfully." << endl;
}


// Шифровка и расшифровка файла
void encodeDecode(FILE* in) {
    FILE* outEncoded, * inEncoded, * outDecoded;
    if ((outEncoded = fopen("5encoded.txt", "w")) == nullptr) {
        printf("5encoded.txt file not opened");
        return;
    }

    if ((outDecoded = fopen("5decoded.txt", "w")) == nullptr) {
        printf("5decoded.txt file not opened");
        return;
    }

    char* key= nullptr;
    printf("Enter encryption key: ");
    scanf("%s", &key);

    int keyIndex;
    int i = 0;
    char ch;

    while (!feof(in)) {
        ch = getc(in);
        keyIndex = i > sizeof(key) ? i % sizeof(key) : i;
        char encryptedChar = ch ^ key[keyIndex];
        putc(encryptedChar, outEncoded);
        i++;
    }

    // Расшифровка
    if ((inEncoded = fopen("5encoded.txt", "r")) == nullptr) {
        printf("5encoded.txt file not opened");
        return;
    }

    i = 0;
    while (!feof(inEncoded)) {
        ch = getc(inEncoded);
        keyIndex = i > sizeof(key) ? i % sizeof(key) : i;
        char decryptedChar = ch & key[keyIndex];
        putc(decryptedChar, outDecoded);
        i++;
    }
}

// Вывод содержимого файла
void printFile(char* name) {
    FILE* in;

    if ((in = fopen(name, "r")) == nullptr) {
        printf("File %s not opened", name);
    }
    else {
        while (!feof(in)) {
            char ch = getc(in);
            printf("%c", ch);
        }
    }
    fclose(in);
}

int main() {
    setlocale(LC_ALL, "Russian");
    char name[50];
    char substring[50];
    FILE* in;

    printf("Enter file name: ");
    scanf("%s", name); //  f.txt

    if ((in = fopen(name, "r")) == nullptr) {
        printf("File %s not opened", name);
    }
    else {
        printFile(name);
        cout << endl;
        visibleInvisible(in);
        cout << endl;
        printf("Enter substring to look for: ");
        scanf("%s", substring);
        cout << endl;
        findSubstring(in, substring);
        cout << endl;
        processPages(name);
        cout << endl;
        encodeDecode(in);
    }
    return 0;
}