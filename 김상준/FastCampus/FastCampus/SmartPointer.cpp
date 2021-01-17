#include <iostream>

int main()
{
	// Smart Pointer
	// �޸� ���� ������ ���� ����, ������ó�� �����ϴ� Ŭ���� ���ø�

	// ����
	// new Ű���带 �̿��� �⺻ �����͸� ���� -> ���� ����Ʈ �����Ϳ� �ش� �����͸� �־ ���

	// ����Ʈ �������� ����
	// unique_ptr: �ϳ��� ����Ʈ �����Ͱ� Ư���� ��ü�� ó��
	// shared_ptr: Ư���� ��ü�� �����ϴ� ����Ʈ �����Ͱ� �� ����� ����
	//             ���ο� ��īƮ �����Ͱ� ������ �� ���� ���� Ƚ���� 1�� ����, ������ ���ϸ� 1 ����
	//             ���� Ƚ���� 0�� �Ǹ� �ڵ����� ����
	//  weak_ptr:  �ϳ� �̻��� shared_ptr �ν��Ͻ��� �����ϴ� ��ü�� ���� ������ ����
	//			   ������ ������ ������ ���Ե��� ����
	//			   ��ȯ ���� ������ �����ϱ� ���� �������� ���

	std::unique_ptr<int> p1(new int(10));
	std::unique_ptr<int> p2;
	std::cout << *p1 << "\n"; // ��ü ������ ���� �����Ϳ� ����
	std::cout << p1 << "\n";
	std::cout << p2 << "\n";
	p2 = move(p1); // ������ ����
	std::cout << p1 << "\n";
	std::cout << p2 << "\n";
	p2.reset(); // �޸� ������ �������� ���� ����Ʈ �����Ϳ��Ը�
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