#include <iostream> //����������� ���������� iostream

int main(void) { // ����������� ������� main
    setlocale(LC_ALL, "Russian");
    int i, k;//���������� ����������
    int power(int, int);//���������� �������
    for (i = 0; i < 10; i++) {//���� �� 0 �� 9
        k = power(2, i); //������������� k �������� �������
        std::cout<< "i = " << i << ",k=" << k << std::endl; //����� i � k
    }

    void exp02(); //���������� ������� 2
    exp02();

    void exp03();//���������� ������� 3
    exp03();
}
int power(int x, int n) {
    int i, p = 1;
    for (i = 1; i < n; i++)p *= x;//n-2 ���� ��������� p �� x
    return p;//����������� �������� p
}