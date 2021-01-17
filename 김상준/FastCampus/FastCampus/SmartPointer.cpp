#include <iostream>

int main()
{
	// Smart Pointer
	// 메모리 누수 방지를 위한 수단, 포인터처럼 동작하는 클래스 템플릿

	// 사용법
	// new 키워드를 이용해 기본 포인터를 생성 -> 이후 스마트 포인터에 해당 포인터를 넣어서 사용

	// 스마트 포인터의 종류
	// unique_ptr: 하나의 스마트 포인터가 특정한 객체를 처리
	// shared_ptr: 특정한 객체를 참조하는 스마트 포인터가 총 몇개인지 참조
	//             새로운 스카트 포인터가 참조할 때 마다 참조 횟수가 1씩 증가, 수명이 다하면 1 감소
	//             참조 횟수가 0이 되면 자동으로 해제
	//  weak_ptr:  하나 이상의 shared_ptr 인스턴스가 소유하는 객체에 대한 접근을 제공
	//			   하지만 소유자 수에는 포함되지 않음
	//			   순환 참조 현상을 제거하기 위한 목적으로 사용

	std::unique_ptr<int> p1(new int(10));
	std::unique_ptr<int> p2;
	std::cout << *p1 << "\n"; // 객체 접근은 원래 포인터와 동일
	std::cout << p1 << "\n";
	std::cout << p2 << "\n";
	p2 = move(p1); // 소유권 이전
	std::cout << p1 << "\n";
	std::cout << p2 << "\n";
	p2.reset(); // 메모리 해제는 소유권을 가진 스마트 포인터에게만
	std::cout << p1 << "\n";
	std::cout << p2 << "\n";
	std::cout << std::endl;

	int* arr = new int[10];
	arr[7] = 100;
	std::shared_ptr<int> p3(arr);
	std::cout << p3.use_count() << "\n";
	std::shared_ptr<int> p4(p3);
	std::cout << p3.use_count() << "\n";
	std::shared_ptr<int> p5(p4);
	std::cout << p3.use_count() << "\n";
	p3.reset();
	p4.reset();
	std::cout << arr[7] << "\n";
	p5.reset();
	std::cout << p3.use_count() << "\n";
	std::cout << arr[7] << "\n";
	std::cout << std::endl;

	int* a = new int(1);
	std::shared_ptr<int> sp1(a);
	std::weak_ptr<int> wp = sp1;
	std::cout << sp1.use_count() << "\n";
	std::cout << wp.use_count() << "\n";
	if (true)
	{
		std::shared_ptr<int> sp2 = wp.lock();
		std::cout << sp1.use_count() << "\n";
		std::cout << wp.use_count() << "\n";
	}
	std::cout << sp1.use_count() << "\n";
	std::cout << wp.use_count() << "\n";
}