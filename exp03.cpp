#include <iostream>
int a = 2, b = 5; //���������� ���������� ����������
void exp03(void) {
	void obmen1(int, int); //���������� �������
	void obmen2(int*, int*);
	void obmen3(int&, int&);
	std::cout << "�� ������: a=" << a << " b=" << b << std::endl; //����� �������� a � b
	obmen1(a, b); //����� �������
	std::cout << "����� ������ 1: a=" << a << " b=" << b << std::endl;//����� �������� a � b
	int* aa{ &a }, * bb{ &b }; //���������� ���������� �� a � b 
	obmen2(aa, bb);//����� �������
	std::cout << "����� ������ 2: a=" << a << " b=" << b << std::endl;//����� �������� a � b
	obmen2(&a, &b);//����� �������
	std::cout << "����� ������ 3: a=" << a << " b=" << b << std::endl;//����� �������� a � b
}
void obmen1(int aa, int bb) { //������� ������ ����������
	int i{aa};
	a = bb;
	b = i;
}
void obmen2(int* aa, int* bb) { //������� ������ ���������� ��� ������ ����������
	int i{*aa}; //���������� � ���������� i �������� ��������� aa
	a = *bb;
	b = i;
}
void obmen3(int& aa, int& bb) { //������� ������ ���������� ��� ������ �������
	int i{ aa };
	a = bb;
	b = i;
}
