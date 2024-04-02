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
		for (j = 0; j < N; j++) m[i][j] = rand() / 10.;//���������� ������� ���������� ����������

	for (i = 0; i < N; i++) {
		for (j = 0; j < N; j++)
			std::cout << std::setw(8) << std::setprecision(5) << m[i][j];
		std::cout << std::endl;
	}//����� ������� � ����������� ����������
	std::cout << std::endl;

	//���������� �������(
	void min(float mas[N][N]), max(float mas[N][N]), maxNT(float mas[N][N]), minNT(float mas[N][N]);
	void maxVT(float mas[N][N]), minVT(float mas[N][N]),maxGD(float mas[N][N]), minGD(float mas[N][N]);
	void maxVD(float mas[N][N]), minVD(float mas[N][N]), sred(float mas[N][N]), sredNT(float mas[N][N]), sredVT(float mas[N][N]);
	void sumStrok(float mas[N][N]), sumStolbcov(float mas[N][N]), minStrok(float mas[N][N]), maxStrok(float mas[N][N]);
	void minStolb(float mas[N][N]), maxStolb(float mas[N][N]), sredStrok(float mas[N][N]), sredStolbcov(float mas[N][N]);
	void sumT(float mas[N][N]), blizjaishiy(float mas[N][N]);
	//����� �������
	min(m);max(m); //������� ��������� ����������� � ������������� �������� � �������

	maxNT(m);minNT(m); //������� ��������� ����������� � ������������� �������� � ���������������� ����� �������
	maxVT(m);minVT(m); // ���������� ��� ����������������� ����� �������

	maxGD(m);minGD(m); //������� ��������� ����������� � ������������� �������� � ������� ��������� �������
	maxVD(m);minVD(m); // ���������� � �������������� ��������� �������

	sred(m); //�������������������� �������� ��������� �������
	sredNT(m); //�������������������� �������� ��������� ���������������� ����� �������
	sredVT(m); //�������������������� �������� ��������� ����������������� ����� �������

	sumStrok(m); //�������� ���� ��������� ������ ������
	sumStolbcov(m); //�������� ���� ��������� ������� �������

	minStrok(m);maxStrok(m); //����������� � ������������ �������� � ������ ������
	
	minStolb(m);maxStolb(m); //����������� � ������������ �������� � ������ �������

	sredStrok(m); //�������� �������� ��������� � ������
	sredStolbcov(m); //�������� �������� ��������� � �������

	sumT(m); //����� ���������������� � ����������������� ������
	blizjaishiy(m); //������� ���������� � ���������������������
}
void min(float mas[N][N]) {
	float x{ mas[0][0] };//������� ���������� ��������, ������������� � �������
	for (i = 0; i < N; i++) //������� �������
		for (j = 0; j < N; j++)
			if (x > mas[i][j])x = mas[i][j];//���������� x ������������ ��������
	std::cout << "min: " << x << "   "; //����� � �������
}
void max(float mas[N][N]) {
	float x{ mas[0][0] }; //������� ���������� ��������, ������������� � �������
	for (i = 0; i < N; i++) //������� �������
		for (j = 0; j < N; j++)
			if (x < mas[i][j])x = mas[i][j];//���������� x ������������� ��������
	std::cout << "max: " << x << std::endl;
	std::cout << std::endl;
}

//��������������
void maxNT(float mas[N][N]) {
	float x{ mas[4][0] }; //������� ���������� ��������, ������������� � ����������� �������
	for (i = 0; i < N; i++) 
		for (j = 0; j < i; j++) //������� ���������������� �����
			if (x < mas[i][j])x = mas[i][j]; //���������� x ������������� ��������
	std::cout << "maxNT: " << x << "   ";
}
void minNT(float mas[N][N]) {
	float x{ mas[4][0] };
	for (i = 0; i < N; i++)
		for (j = 0; j < i; j++)
			if (x > mas[i][j])x = mas[i][j]; //���������� x ������������ ��������
	std::cout << "minNT: " << x << std::endl;
}

//���������������
void maxVT(float mas[N][N]) {
	float x{ mas[0][4] }; //������� ���������� ��������, ������������� � ����������� �������
	for (i = 0; i < N; i++)
		for (j = i+1; j < N; j++) //������� ����������������� �����
			if (x < mas[i][j])x = mas[i][j]; //���������� x ������������� ��������
	std::cout << "maxVT: " << x << "   ";
}
void minVT(float mas[N][N]) {
	float x{ mas[0][4] };
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++)
			if (x > mas[i][j])x = mas[i][j]; //���������� x ������������ ��������
	std::cout << "minVT: " << x << std::endl;
	std::cout << std::endl;
}

//������� ���������
void maxGD(float mas[N][N]) {
	float x{ mas[0][0] }; //������� ���������� ��������, ������������� � ����������� �������
	for (i = 0; i < N; i++) //������� ������� ���������
			if (x < mas[i][i])x = mas[i][i]; //���������� x ������������� ��������
	std::cout << "maxGD: " << x << "   ";
}
void minGD(float mas[N][N]) {
	float x{ mas[0][0] }; //������� ���������� ��������, ������������� � ����������� �������
	for (i = 0; i < N; i++) //������� ������� ���������
		if (x > mas[i][i])x = mas[i][i]; //���������� x ������������ ��������
	std::cout << "minGD: " << x << std::endl;
}

//�������������� ���������
void maxVD(float mas[N][N]) {
	float x{ mas[0][4] }; //������� ���������� ��������, ������������� � ����������� �������
	for (i = 0; i < N; i++) //������� �������������� ���������
			if (x < mas[i][4-i])x = mas[i][4-i]; //���������� x ������������� ��������
	std::cout << "maxVD: " << x << "   ";
}
void minVD(float mas[N][N]) {
	float x{ mas[0][4] }; //������� ���������� ��������, ������������� � ����������� �������
	for (i = 0; i < N; i++) //������� �������������� ���������
		if (x > mas[i][4-i])x = mas[i][4-i]; //���������� x ������������ ��������
	std::cout << "minVD: " << x << std::endl;
	std::cout << std::endl;
}

//��������������������
void sred(float mas[N][N]) {
	float sum{ 0.0 };
	for (i = 0; i < N; i++) //������� �������
		for (j = 0; j < N; j++)
			sum+=mas[i][j];//������������ ���� ��������
	std::cout << "srednee: " << sum/(N*N)<< std::endl; //����� � �������
}
void sredNT(float mas[N][N]) {
	float sum{ 0.0 };
	for (i = 0; i < N; i++)
		for (j = 0; j < i; j++) //������� ���������������� �����
			sum += mas[i][j];//������������ �������� ���������������� �����
	std::cout << "sredneeNT: " << sum / ((N * N)/2-N/2) << std::endl; //����� � �������
}
void sredVT(float mas[N][N]) {
	float sum{ 0.0 };
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++) //������� ��������������� �����
			sum += mas[i][j];//������������ �������� ��������������� �����
	std::cout << "sredneeVT: " << sum / ((N * N) / 2 - N / 2) << std::endl; //����� � �������
	std::cout << std::endl;
}

//������ � �������
void sumStrok(float mas[N][N]) {
	float sum{ 0.0 };
	std::cout << "sumStrok: ";
	for (i = 0; i < N; i++) {//������� �������
		sum= 0;//��������� ��������
		for (j = 0; j < N; j++)
			sum += mas[i][j];//������������ �������� ������
		std::cout << std::setw(8) << std::setprecision(5) << sum << " ";
	}
	std::cout << std::endl; //������� ������
}
void sumStolbcov(float mas[N][N]) {
	float sum{ 0.0 };
	std::cout << "sumSolbcov: ";
	for (i = 0; i < N; i++) {//������� �������
		sum = 0;//��������� ��������
		for (j = 0; j < N; j++)
			sum += mas[j][i];//������������ �������� ��������
		std::cout << std::setw(8) << std::setprecision(5) << sum << " ";
	}
	std::cout << std::endl; //������� ������
	std::cout << std::endl;
}

void minStrok(float mas[N][N]) {
	float sum{ 0.0 }, x{mas[0][0]};
	std::cout << "minStrok: ";
	for (i = 0; i < N; i++) {//������� �������
		x = mas[i][0]; sum = 0;//��������� ��������
		for (j = 0; j < N; j++)
			if (x>mas[i][j])x=mas[i][j];//��������� ������������ �������� � ������
		std::cout << std::setw(8) << std::setprecision(5) << x << " ";
	}
	std::cout << std::endl; //������� ������
	
}
void maxStrok(float mas[N][N]) {
	float sum{ 0.0 }, x{ mas[0][0] };
	std::cout << "maxStrok: ";
	for (i = 0; i < N; i++) {//������� �������
		x = mas[i][0]; sum = 0;//��������� ��������
		for (j = 0; j < N; j++)
			if (x < mas[i][j])x = mas[i][j];//��������� ������������� �������� � ������
		std::cout << std::setw(8) << std::setprecision(5) << x << " ";
	}
	std::cout << std::endl; //������� ������
	std::cout << std::endl;
}

void minStolb(float mas[N][N]) {
	float sum{ 0.0 }, x{ mas[0][0] };
	std::cout << "minStolb: ";
	for (i = 0; i < N; i++) {//������� �������
		x = mas[0][i]; sum = 0;//��������� ��������
		for (j = 0; j < N; j++)
			if (x > mas[j][i])x = mas[j][i];//��������� ������������ �������� � �������
		std::cout << std::setw(8) << std::setprecision(5) << x << " ";
	}
	std::cout << std::endl; //������� ������
}
void maxStolb(float mas[N][N]) {
	float sum{ 0.0 }, x{ mas[0][0] };
	std::cout << "maxStolb: ";
	for (i = 0; i < N; i++) {//������� �������
		x = mas[0][i]; sum = 0;//��������� ��������
		for (j = 0; j < N; j++)
			if (x < mas[j][i])x = mas[j][i];//��������� ������������� �������� � �������
		std::cout << std::setw(8) << std::setprecision(5) << x << " ";
	}
	std::cout << std::endl; //������� ������
	std::cout << std::endl;
}

void sredStrok(float mas[N][N]) {
	float sum{ 0.0 };
	std::cout << "sredStrok: ";
	for (i = 0; i < N; i++) {//������� �������
		sum = 0;//��������� ��������
		for (j = 0; j < N; j++)
			sum += mas[i][j];//������������ �������� ������
		std::cout << std::setw(8) << std::setprecision(5) << sum/N << " ";
	}
	std::cout << std::endl; //������� ������
}

void sredStolbcov(float mas[N][N]) {
	float sum{ 0.0 };
	std::cout << "sredSolbcov: ";
	for (i = 0; i < N; i++) {//������� �������
		sum = 0;//��������� ��������
		for (j = 0; j < N; j++)
			sum += mas[j][i];//������������ �������� ��������
		std::cout << std::setw(8) << std::setprecision(5) << sum/N << " ";
	}
	std::cout << std::endl; //������� ������
	std::cout << std::endl;
}

//����� ���������������� � ����������������� ������
void sumT(float mas[N][N]) {
	float sum{ 0.0 };
	for (i = 0; i < N; i++)
		for (j = 0; j < i; j++) //������� ���������������� �����
			sum += mas[i][j];//������������ �������� ���������������� �����
	for (i = 0; i < N; i++)
		for (j = i + 1; j < N; j++) //������� ��������������� �����
			sum += mas[i][j]; //������������ �������� ��������������� �����
	std::cout << "sumTreug: " << sum  << std::endl; //����� � �������
}

//������� ���������� � ���������������������
void blizjaishiy(float mas[N][N]) {
	float sum{ 0.0 }, x{ mas[0][0] }, z{ 0 };
	for (i = 0; i < N; i++) //������� �������
		for (j = 0; j < N; j++) {
			sum += mas[i][j];//������������ ���� ��������
			if (x < mas[i][j])x = mas[i][j];//���������� x ������������� ��������
		}
	sum = sum / (N * N);//���������� ���������������������
	for (i = 0; i < N; i++)
		for (j = 0; j < N; j++)
			if (x > abs(mas[i][j] - sum)) {//����������� ���������� ������
				z = mas[i][j]; x = abs(mas[i][j] - sum);
			}
	std::cout << "blizjaishiy: " << z << std::endl; //����� � �������
}
