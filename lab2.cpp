#include <iostream>
#include<iomanip>
#include<stdlib.h>
#include<conio.h>
#define N 5
int i, j;

void main() {
	float m[N][N];
	int i, j;
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++) m[i][j] = rand() / 10.;//наполнение массива случайными значениями

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			std::cout << std::setw(8) << std::setprecision(5) << m[i][j];
		std::cout << std::endl;
	}//вывод массива с соблюдением расстояния
	std::cout << std::endl;

	//объявление функций(
	void min(float mas[N][N]), max(float mas[N][N]), maxNT(float mas[N][N]), minNT(float mas[N][N]);
	void maxVT(float mas[N][N]), minVT(float mas[N][N]),maxGD(float mas[N][N]), minGD(float mas[N][N]);
	void maxVD(float mas[N][N]), minVD(float mas[N][N]), sred(float mas[N][N]), sredNT(float mas[N][N]), sredVT(float mas[N][N]);
	void sumStrok(float mas[N][N]), sumStolbcov(float mas[N][N]), minStrok(float mas[N][N]), maxStrok(float mas[N][N]);
	void minStolb(float mas[N][N]), maxStolb(float mas[N][N]), sredStrok(float mas[N][N]), sredStolbcov(float mas[N][N]);
	void sumT(float mas[N][N]), blizjaishiy(float mas[N][N]);
	//вызов функций
	min(m);max(m); //функции находящие минимальное и максимального значение в массиве

	maxNT(m);minNT(m); //функции находящие минимальное и максимального значение в нижнетреугольной части массиве
	maxVT(m);minVT(m); // аналогично для верхнетреугольной части массиве

	maxGD(m);minGD(m); //функции находящие минимальное и максимального значение в главной диагонали массива
	maxVD(m);minVD(m); // аналогично в второстепенной диагонали массива

	sred(m); //среднеарифметическое значение элементов массива
	sredNT(m); //среднеарифметическое значение элементов нижнетреугольной части массива
	sredVT(m); //среднеарифметическое значение элементов верхнетреугольной части массива

	sumStrok(m); //значения сумм элементов каждой строки
	sumStolbcov(m); //значения сумм элементов каждого столбца

	minStrok(m);maxStrok(m); //минимальное и максимальное значение в каждой строке
	
	minStolb(m);maxStolb(m); //минимальное и максимальное значение в каждом столбце

	sredStrok(m); //стреднее значение элементов в строке
	sredStolbcov(m); //стреднее значение элементов в стоблце

	sumT(m); //сумма нижнетреугольной и верхнетреугольной частей
	blizjaishiy(m); //элемент близжайший к среднеарифметическому
}
void min(float mas[N][N]) {
	float x{ mas[0][0] };//задание стартового значения, существующего в матрице
	for (i = 0; i < N; i++) //перебор матрицы
		for (j = 0; j < N; j++)
			if (x > mas[i][j])x = mas[i][j];//присвоение x минимального значения
	std::cout << "min: " << x << "   "; //вывод в консоль
}
void max(float mas[N][N]) {
	float x{ mas[0][0] }; //задание стартового значения, существующего в матрице
	for (i = 0; i < N; i++) //перебор матрицы
		for (j = 0; j < N; j++)
			if (x < mas[i][j])x = mas[i][j];//присвоение x максимального значения
	std::cout << "max: " << x << std::endl;
	std::cout << std::endl;
}

//нижнетреульная
void maxNT(float mas[N][N]) {
	float x{ mas[4][0] }; //задание стартового значения, существующего в исследуемой области
	for (i = 0; i < N; i++) 
		for (j = 0; j < i; j++) //перебор нижнетреугольной части
			if (x < mas[i][j])x = mas[i][j]; //присвоение x максимального значения
	std::cout << "maxNT: " << x << "   ";
}
void minNT(float mas[N][N]) {
	float x{ mas[4][0] };
	for (i = 0; i < N; i++)
		for (j = 0; j < i; j++)
			if (x > mas[i][j])x = mas[i][j]; //присвоение x минимального значения
	std::cout << "minNT: " << x << std::endl;
}

//верхнетреульная
void maxVT(float mas[N][N]) {
	float x{ mas[0][4] }; //задание стартового значения, существующего в исследуемой области
	for (i = 0; i < N; i++)
		for (j = i+1; j < N; j++) //перебор верхнетреугольной части
			if (x < mas[i][j])x = mas[i][j]; //присвоение x максимального значения
	std::cout << "maxVT: " << x << "   ";
}
void minVT(float mas[N][N]) {
	float x{ mas[0][4] };
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (x > mas[i][j])x = mas[i][j]; //присвоение x минимального значения
	std::cout << "minVT: " << x << std::endl;
	std::cout << std::endl;
}

//главная диагональ
void maxGD(float mas[N][N]) {
	float x{ mas[0][0] }; //задание стартового значения, существующего в исследуемой области
	for (i = 0; i < N; i++) //перебор главной диагонали
			if (x < mas[i][i])x = mas[i][i]; //присвоение x максимального значения
	std::cout << "maxGD: " << x << "   ";
}
void minGD(float mas[N][N]) {
	float x{ mas[0][0] }; //задание стартового значения, существующего в исследуемой области
	for (i = 0; i < N; i++) //перебор главной диагонали
		if (x > mas[i][i])x = mas[i][i]; //присвоение x минимального значения
	std::cout << "minGD: " << x << std::endl;
}

//второстепенная диагональ
void maxVD(float mas[N][N]) {
	float x{ mas[0][4] }; //задание стартового значения, существующего в исследуемой области
	for (i = 0; i < N; i++) //перебор второстепенной диагонали
			if (x < mas[i][4-i])x = mas[i][4-i]; //присвоение x максимального значения
	std::cout << "maxVD: " << x << "   ";
}
void minVD(float mas[N][N]) {
	float x{ mas[0][4] }; //задание стартового значения, существующего в исследуемой области
	for (i = 0; i < N; i++) //перебор второстепенной диагонали
		if (x > mas[i][4-i])x = mas[i][4-i]; //присвоение x минимального значения
	std::cout << "minVD: " << x << std::endl;
	std::cout << std::endl;
}

//среднеарифметическое
void sred(float mas[N][N]) {
	float sum{ 0.0 };
	for (i = 0; i < N; i++) //перебор матрицы
		for (j = 0; j < N; j++)
			sum+=mas[i][j];//суммирование всех значений
	std::cout << "srednee: " << sum/(N*N)<< std::endl; //вывод в консоль
}
void sredNT(float mas[N][N]) {
	float sum{ 0.0 };
	for (i = 0; i < N; i++)
		for (j = 0; j < i; j++) //перебор нижнетреугольной части
			sum += mas[i][j];//суммирование значений нижнетреугольной части
	std::cout << "sredneeNT: " << sum / ((N * N)/2-N/2) << std::endl; //вывод в консоль
}
void sredVT(float mas[N][N]) {
	float sum{ 0.0 };
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++) //перебор верхнетреульной части
			sum += mas[i][j];//суммирование значений верхнетреульной части
	std::cout << "sredneeVT: " << sum / ((N * N) / 2 - N / 2) << std::endl; //вывод в консоль
	std::cout << std::endl;
}

//строки и столбцы
void sumStrok(float mas[N][N]) {
	float sum{ 0.0 };
	std::cout << "sumStrok: ";
	for (i = 0; i < N; i++) {//перебор матрицы
		sum= 0;//обнуление счетчика
		for (j = 0; j < N; j++)
			sum += mas[i][j];//суммирование значений строки
		std::cout << std::setw(8) << std::setprecision(5) << sum << " ";
	}
	std::cout << std::endl; //перевод строки
}
void sumStolbcov(float mas[N][N]) {
	float sum{ 0.0 };
	std::cout << "sumSolbcov: ";
	for (i = 0; i < N; i++) {//перебор матрицы
		sum = 0;//обнуление счетчика
		for (j = 0; j < N; j++)
			sum += mas[j][i];//суммирование значений столбцов
		std::cout << std::setw(8) << std::setprecision(5) << sum << " ";
	}
	std::cout << std::endl; //перевод строки
	std::cout << std::endl;
}

void minStrok(float mas[N][N]) {
	float sum{ 0.0 }, x{mas[0][0]};
	std::cout << "minStrok: ";
	for (i = 0; i < N; i++) {//перебор матрицы
		x = mas[i][0]; sum = 0;//обнуление счетчика
		for (j = 0; j < N; j++)
			if (x>mas[i][j])x=mas[i][j];//выявление минимального значения в строке
		std::cout << std::setw(8) << std::setprecision(5) << x << " ";
	}
	std::cout << std::endl; //перевод строки
	
}
void maxStrok(float mas[N][N]) {
	float sum{ 0.0 }, x{ mas[0][0] };
	std::cout << "maxStrok: ";
	for (i = 0; i < N; i++) {//перебор матрицы
		x = mas[i][0]; sum = 0;//обнуление счетчика
		for (j = 0; j < N; j++)
			if (x < mas[i][j])x = mas[i][j];//выявление максимального значения в строке
		std::cout << std::setw(8) << std::setprecision(5) << x << " ";
	}
	std::cout << std::endl; //перевод строки
	std::cout << std::endl;
}

void minStolb(float mas[N][N]) {
	float sum{ 0.0 }, x{ mas[0][0] };
	std::cout << "minStolb: ";
	for (i = 0; i < N; i++) {//перебор матрицы
		x = mas[0][i]; sum = 0;//обнуление счетчика
		for (j = 0; j < N; j++)
			if (x > mas[j][i])x = mas[j][i];//выявление минимального значения в столбце
		std::cout << std::setw(8) << std::setprecision(5) << x << " ";
	}
	std::cout << std::endl; //перевод строки
}
void maxStolb(float mas[N][N]) {
	float sum{ 0.0 }, x{ mas[0][0] };
	std::cout << "maxStolb: ";
	for (i = 0; i < N; i++) {//перебор матрицы
		x = mas[0][i]; sum = 0;//обнуление счетчика
		for (j = 0; j < N; j++)
			if (x < mas[j][i])x = mas[j][i];//выявление максимального значения в столбце
		std::cout << std::setw(8) << std::setprecision(5) << x << " ";
	}
	std::cout << std::endl; //перевод строки
	std::cout << std::endl;
}

void sredStrok(float mas[N][N]) {
	float sum{ 0.0 };
	std::cout << "sredStrok: ";
	for (i = 0; i < N; i++) {//перебор матрицы
		sum = 0;//обнуление счетчика
		for (j = 0; j < N; j++)
			sum += mas[i][j];//суммирование значений строки
		std::cout << std::setw(8) << std::setprecision(5) << sum/N << " ";
	}
	std::cout << std::endl; //перевод строки
}

void sredStolbcov(float mas[N][N]) {
	float sum{ 0.0 };
	std::cout << "sredSolbcov: ";
	for (i = 0; i < N; i++) {//перебор матрицы
		sum = 0;//обнуление счетчика
		for (j = 0; j < N; j++)
			sum += mas[j][i];//суммирование значений столбцов
		std::cout << std::setw(8) << std::setprecision(5) << sum/N << " ";
	}
	std::cout << std::endl; //перевод строки
	std::cout << std::endl;
}

//сумма нижнетреугольной и верхнетреугольной частей
void sumT(float mas[N][N]) {
	float sum{ 0.0 };
	for (i = 0; i < N; i++)
		for (j = 0; j < i; j++) //перебор нижнетреугольной части
			sum += mas[i][j];//суммирование значений нижнетреугольной части
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++) //перебор верхнетреульной части
			sum += mas[i][j]; //суммирование значений верхнетреульной части
	std::cout << "sumTreug: " << sum  << std::endl; //вывод в консоль
}

//элемент близжайший к среднеарифметическому
void blizjaishiy(float mas[N][N]) {
	float sum{ 0.0 }, x{ mas[0][0] }, z{ 0 };
	for (i = 0; i < N; i++) //перебор матрицы
		for (j = 0; j < N; j++) {
			sum += mas[i][j];//суммирование всех значений
			if (x < mas[i][j])x = mas[i][j];//присвоение x максимального значения
		}
	sum = sum / (N * N);//вычисление среднеарифметического
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (x > abs(mas[i][j] - sum)) {//сравнивание абсолютных разниц
				z = mas[i][j]; x = abs(mas[i][j] - sum);
			}
	std::cout << "blizjaishiy: " << z << std::endl; //вывод в консоль
}
