#include <iostream>
int a = 2, b = 5; //объ€вление глобальных переменных
void exp03(void) {
	void obmen1(int, int); //объ€вление функций
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	std::cout << "до обмена: a=" << a << " b=" << b << std::endl; //вывод значени€ a и b
	obmen1(a, b); //вызов функции
	std::cout << "после обмена 1: a=" << a << " b=" << b << std::endl;//вывод значени€ a и b
	int* aa{ &a }, * bb{ &b }; //объ€вление указателей на a и b 
	obmen2(aa, bb);//вызов функции
	std::cout << "после обмена 2: a=" << a << " b=" << b << std::endl;//вывод значени€ a и b
	obmen2(&a, &b);//вызов функции
	std::cout << "после обмена 3: a=" << a << " b=" << b << std::endl;//вывод значени€ a и b
}
void obmen1(int aa, int bb) { //функци€ обмена переменных
	int i{aa};
	a = bb;
	b = i;
}
void obmen2(int* aa, int* bb) { //функци€ обмена переменных при помощи указателей
	int i{*aa}; //объ€вление и присвоение i значени€ указател€ aa
	a = *bb;
	b = i;
}
void obmen3(int& aa, int& bb) { //функци€ обмена переменных при помощи адресов
	int i{ aa };
	a = bb;
	b = i;
}
