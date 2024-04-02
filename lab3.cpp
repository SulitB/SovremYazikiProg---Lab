#include <iostream>
#include <conio.h>
using namespace std;
int mas[] = { 2,5,-8,1,-4,6,3,-5,-9,13,0,4,9 };
int mas1[] = { 2,5,-8,1,-4,6,3,-5,-9,13,0,4,9 };
int n = sizeof(mas) / sizeof(int);
int i{ 0 }, e{ 0 },nn=n;
int nm{0};

void minimax() {
	int imin, imax;
	imin = imax = i;
	//clrscr();
	for (i = 0; i < n; i++) cout << mas[i] << ' ';
	cout << endl;
	for (i = 0; i < n - 1; i++) {
		imin = i;
		for (int j = i + 1; j < n; j++)
			if (mas[j] < mas[imin]) imin = j;
		int t = mas[i];
		mas[i] = mas[imin];
		mas[imin] = t;
	}
	for (i = 0; i < n; i++) cout << mas[i] << ' ';
	cout << endl;
}
void puzir() {
	int n1{0};
	int mas[] = { 2,5,-8,1,-4,6,3,-5,-9,13,0,4,9};
	for (i = 0; i < n; i++) cout << mas[i] << ' ';
	cout << endl;
	while (n1< n-1){//���������� ����������� ���� ������� ������� �� ��������� ��� ������ ���������
		n1 = 0;
		for (i = 1; i < n; i++) {
			if (mas[i - 1] > mas[i]) {//����� �������� ��������� ���� ���������� ������ ����������
				int t = mas[i - 1];
				mas[i - 1] = mas[i]; 
				mas[i] = t;
			}
			else n1++;
		}
	}
	for (i = 0; i < n; i++) cout << mas[i] << ' ';
	cout << endl;
}
void bistriy(int* mas, int size) {
	i = 0;//��������� � ������ � � ����� �������
	int ii = size - 1;	
	int mid = mas[size / 2];//����������� ������� �������

	do {
		//� ����� ����� ������� ����������(��������� �� �����) ��������, ������� ������ ������������
		while (mas[i] < mid) {//����� ����� �������� ������ ������������
			i++;}
		while (mas[ii] > mid) {//����� ������ �������� ������ ������������
			ii--;}
		if (i <= ii) {//������ �������� �������
			int t = mas[i];
			mas[i] = mas[ii];
			mas[ii] = t;
			i++;
			ii--;
		}
	} while (i <= ii);//���������� ���� ����� �� ����� �������� ������, � ������ ������ ������������
	
	for (int j = 0; j < n; j++) cout << mas[j] << ' ';
	cout << endl;
	
	if (ii > 0) //�������� ��� ����� �����
		bistriy(mas, ii + 1);
	if (i < size) //�������� ��� ������ �����
		bistriy(&mas[i], size - i);
}
void chetnechet() {
	int ch{ 0 }, nch{ 0 };
	for (int i: mas) {//������� ���-�� ������ � �������� ���������
		if (i % 2 == 0) ch++;
		else nch++;
	}
	while (ch > 0) {
		for (int q = 0; q < n; q++) {
			if (mas[q] % 2 == 0) {//���������� ������� ������� ��������
				for (int qq = q + 1; qq < n; qq++) {
					if (mas[qq] % 2 == 0) {//���������� ���������� ������� ��������
						if (mas[qq] < mas[q]) {//���� ��������� ������� ������ ����������� �� ����� �������
							int t = mas[q];
							mas[q] = mas[qq];
							mas[qq] = t;
						}
						else ch--;//������� �������� ��� ����� ���������
					}
				}
			}
		}
	}
	while (nch > 0) {
		for (int q = 0; q < n; q++) {
			if (mas[q] % 2 != 0) {//���������� ������� ��������� ��������
				for (int qq = q + 1; qq < n; qq++) {
					if (mas[qq] % 2 != 0) {//���������� ���������� ��������� ��������
						if (mas[qq] > mas[q]) {//���� ��������� ������� ������ ����������� �� ����� �������
							int t = mas[q];
							mas[q] = mas[qq];
							mas[qq] = t;
						}
						else nch--;//������� �������� ��� ����� ���������
					}
				}
			}
		}
	}
}
void vozrast(int q,int qq) {
	for (q; q < qq;q++) {//�������� ������� � ��������� �� q �� qq
		for (i = q + 1; i < qq; i++) {
			if (mas[q] > mas[i]) { //����� ������� ���� ���� ������� ������
				int t = mas[q];
				mas[q] = mas[i];
				mas[i] = t;
			}
		}
	}
}
void ubivanie(int q, int qq) {
	for (q; q < qq; q++) {//�������� ������� � ��������� �� q �� qq
		for (i = q + 1; i < qq; i++) {
			if (mas[q] < mas[i]) {//����� ������� ���� ���� ������� ������
				int t = mas[q];
				mas[q] = mas[i];
				mas[i] = t;
			}
		}
	}
}

void main(void) {
	setlocale(LC_ALL, "Russian");
	for (int j = 0; j < n; j++) cout << mas[j] << ' ';
	cout << endl;
	//sdvig(1, 4);
	//minimax(); //����-����
	//puzir(); //������

	//for (int j = 0; j < n; j++) mas[i] = mas1[i]; //�������������� �������
	
	//bistriy(mas, n); //������� �����
	//chetnechet(); //����������� ������ � �������� ��������
	//vozrast(2,8);  //����������� � ���������
	ubivanie(2, 7);  //�������� � ���������
	for (int j = 0; j < n; j++) cout << mas[j] << ' ';
	cout << endl;

}