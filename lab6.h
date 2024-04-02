using namespace std;

class String {
    char* str;

public:
    // Конструктор по умолчанию инициализирует str динамическим массивом размером 50
    inline String() {
        str = new char[50];
    };
    // Конструктор, который инициализирует str заданным массивом символов
    inline explicit String(const char*);
    inline String(const String&);// Конструктор копирующий строку
    inline String& operator=(const String&);// Переопределение оператора присваивания
    inline String& operator+(const String&);// Переопределение оператора конкатенации
    inline int operator==(const String&);// Переопределение оператора равенства
    inline int length();// Функция для вычисления длины строки
    inline void input();// Функция для ввода строки
    inline void output();// Функция для вывода строки

    // lab8
    //функции определены как дружественные, чтобы они могли получить доступ к приватным членам класса
    inline friend istream& operator>>(istream& s, String& str);
    inline friend ostream& operator<<(ostream& s, String& str);
};

// lab8
istream& operator>>(istream& s, String& str);//Считывает строку из входного потока и сохраняет ее в текущем объекте
ostream& operator<<(ostream& s, String& str);//Выводит содержимое текущего объекта в выходной поток
