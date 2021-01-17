#include <iostream>
#include <string>
using namespace std;

template <typename T>
void change(T& a, T& b)
{
	T temp;
	temp = a;
	a = b;
	b = temp;
}

template <>
void change<int>(int& a, int& b)
{
	cout << "int\n";
	int temp;
	temp = a;
	a = b;
	b = temp;
}

template <typename T = int>
class Data
{
private:
	T data;
public:
	Data(T data) : data(data) {}
	void SetData(T data) { this->data = data; }
	T GetData() { return data; }
};

int main()
{
	// Template
	// Generic Programming (�Ϲ�ȭ ���α׷���)�� ������ ��� -> ���ø��� �̿�
	// ó�� ȣ���� �� ��, �ڷ����� �´� �ν��Ͻ��� ���� -> �ش� �ڷ����� ���� Ư��ȭ
	string a = "Na";
	string b = "Hong";
	change(a, b);
	cout << a << " " << b << endl;

	// ����� Ư��ȭ
	// Ư�� Ÿ�Կ� ���� Ư�� ����� ���� ����
	int c = 7;
	int d = 5;
	change(c, d);
	cout << c << " " << d << endl;

	// Ŭ���� ���ø�
	// ���ø��� ����Ͽ� �ڷ����� ���� �ٸ� Ŭ���� ������ ���� ����
	// ����Ʈ ���ø� �μ� ���� ����
	Data<> data1(1);
	Data<string> data2("Na");
	cout << data1.GetData() << " " << data2.GetData() << "\n";
}