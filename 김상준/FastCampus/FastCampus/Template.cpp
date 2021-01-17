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
	// Generic Programming (일반화 프로그래밍)이 가능한 언어 -> 템플릿을 이용
	// 처음 호출이 될 때, 자료형에 맞는 인스턴스가 생성 -> 해당 자료형에 대해 특수화
	string a = "Na";
	string b = "Hong";
	change(a, b);
	cout << a << " " << b << endl;

	// 명시적 특수화
	// 특정 타입에 대해 특정 기능을 정의 가능
	int c = 7;
	int d = 5;
	change(c, d);
	cout << c << " " << d << endl;

	// 클래스 템플릿
	// 템플릿을 사용하여 자료형에 따라 다른 클래스 집합을 생성 가능
	// 디폴트 템플릿 인수 설정 가능
	Data<> data1(1);
	Data<string> data2("Na");
	cout << data1.GetData() << " " << data2.GetData() << "\n";
}