using namespace std;

class String {
    char* str;

public:
    // ����������� �� ��������� �������������� str ������������ �������� �������� 50
    inline String() {
        str = new char[50];
    };
    // �����������, ������� �������������� str �������� �������� ��������
    inline explicit String(const char*);
    inline String(const String&);// ����������� ���������� ������
    inline String& operator=(const String&);// ��������������� ��������� ������������
    inline String& operator+(const String&);// ��������������� ��������� ������������
    inline int operator==(const String&);// ��������������� ��������� ���������
    inline int length();// ������� ��� ���������� ����� ������
    inline void input();// ������� ��� ����� ������
    inline void output();// ������� ��� ������ ������

    // lab8
    //������� ���������� ��� �������������, ����� ��� ����� �������� ������ � ��������� ������ ������
    inline friend istream& operator>>(istream& s, String& str);
    inline friend ostream& operator<<(ostream& s, String& str);
};

// lab8
istream& operator>>(istream& s, String& str);//��������� ������ �� �������� ������ � ��������� �� � ������� �������
ostream& operator<<(ostream& s, String& str);//������� ���������� �������� ������� � �������� �����
