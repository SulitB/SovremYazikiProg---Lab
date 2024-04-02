#include <iostream>
#include <memory>

using namespace std;
void main(void) { //main с использованием динамической памяти
	setlocale(LC_ALL, "Russian");
	char* str1, * str2; int j{ 0 };
	str1 = (char*)malloc(100);
	str2 = (char*)calloc(100,sizeof(char));

	char str3[] = "qwerty", str4[] = "1234567890";//заполнение массивов стартовыми значениями
	for (j = 0; j < strlen(str3); j++) str1[j] = str3[j];
	str1[j++] = '\0';
	for (j = 0; j < strlen(str4); j++) str2[j] = str4[j];
	str2[j++] = '\0';

	int dlina1(char*);
	int dlina2(char*);
	int dlina3(char*);
	void kopir(char*, char*);
	string sravn(char*, char*);
	void konkat(char*, char*);

	cout << "длина1 str1=" << dlina1(str1) << ", str2=" << dlina1(str2) << endl;
	cout << "длина2 str1=" << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
	cout << "длина3 str1=" << dlina3(str1) << ", str2=" << dlina3(str2) << endl;
	kopir(str1, str2);
	cout << "результат копирования: str1=" << str1 << ", str2=" << str2 << endl;
	cout << "результат сравнения: " << sravn(str2, str1) << endl;
	konkat(str2, str1);
	cout << "результат сцепления: " << str2 << endl;

	free(str1);
	free(str2);
}

/*
void main(void) {
	char str1[100] = "qwerty", str2[100] = "1234567890";
	int dlina1(char*);
	int dlina2(char*);
	int dlina3(char*);
	void kopir(char*, char*);
	string sravn(char*, char*);
	void konkat(char*, char*);

	cout << "длина1 str1=" << dlina1(str1) << ", str2=" << dlina1(str2) << endl;
	cout << "длина2 str1=" << dlina2(str1) << ", str2=" << dlina2(str2) << endl;
	cout << "длина3 str1=" << dlina3(str1) << ", str2=" << dlina3(str2) << endl;
	kopir(str1, str2);
	cout << "результат копирования: str1=" << str1 << ", str2=" << str2 << endl;
	cout << "результат сравнения: " << sravn(str2, str1) << endl;
	konkat(str2, str1);
	cout << "результат сцепления: " << str2 << endl;
}
*/
int dlina1(char* A) {
	return strlen(A);
}
int dlina2(char* A) {
	int i{ 0 };
	while (A[i])//цикл будет увевиливать i до тех пор пока не получит последнее значение строки, равное 0
		i++;
	return i;
}
int dlina3(char* A) {
	int i;
	for (i = 0; A[i]; i++);//цикл будет увевиливать i до тех пор пока не получит последнее значение строки, равное 0
	return i;
}
void kopir(char* A, char* B) {
	//snprintf(B, strlen(B),"%s", A);
	int i; //по символьное копирование массивов
	for (i = 0; A[i]; i++)
		B[i] = A[i];
	B[i] = '\0';
}
string sravn(char* A,char* B) {
	int i{ 0 };
	while (A[i]) {//по символьное сравнивание массивов символов
		if (A[i] != B[i]) {
			return "False";}
		i++;
	}
	return "True";
}
void konkat(char* A,char* B) {
	int i{ 0 }, j{ 0 };
	j = strlen(A);
	while (B[i]and i< strlen(A)) {//по символьное добавление
		A[j] = B[i];
		i++;j++;
	}
	A[j] = '\0'; //символ окончания строки
}
