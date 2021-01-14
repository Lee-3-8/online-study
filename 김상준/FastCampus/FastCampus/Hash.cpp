#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

// ------------------------------- ���� ����� ------------------------------- //
struct Student
{
	int id;
	char name[20];
};

void Init(Student** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable[i] = NULL;
	}
}

void Destructor(Student** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i])
		{
			delete hashTable[i];
		}
	}
}

int FindEmpty(Student** hashTable, int id)
{
	int i = id % TABLE_SIZE;
	while (true)
	{
		if (!hashTable[i % TABLE_SIZE])
		{
			return i % TABLE_SIZE;
		}
		i++;
	}
}

int Search(Student** hashTable, int id)
{
	int i = id % TABLE_SIZE;
	while (true)
	{
		if (!hashTable[i % TABLE_SIZE]) return -1;
		else if (hashTable[i % TABLE_SIZE]->id == id) return i;
		i++;
	}
}

void Add(Student** hashTable, Student* input, int key)
{
	hashTable[key] = input;
}

Student* GetValue(Student** hashTable, int key)
{
	return hashTable[key];
}

void Show(Student** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i])
		{
			std::cout << "Ű: [" << i << "] �̸�: [" << hashTable[i]->name << "]\n";
		}
	}
}

// ------------------------------- ü�̴� ------------------------------- //
struct Bucket
{
	Student* data;
	Bucket* next;
};

void init(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		hashTable[i] = NULL;
	}
}

void destructor(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i])
		{
			delete hashTable[i];
		}
	}
}

int isExist(Bucket** hashTable, int id)
{
	int i = id % TABLE_SIZE;
	if (hashTable[i] == NULL) return 0;
	else
	{
		Bucket* cur = hashTable[i];
		while (cur != NULL)
		{
			if (cur->data->id == id) return 1;
			cur = cur->next;
		}
	}
	return 0;
}

void add(Bucket** hashTable, Student* input)
{
	int i = input->id % TABLE_SIZE;
	if (hashTable[i] == NULL)
	{
		hashTable[i] = new Bucket;
		hashTable[i]->data = input;
		hashTable[i]->next = NULL;
	}
	else
	{
		Bucket* cur = new Bucket;
		cur->data = input;
		cur->next = hashTable[i];
		hashTable[i] = cur;
	}
}

void show(Bucket** hashTable)
{
	for (int i = 0; i < TABLE_SIZE; i++)
	{
		if (hashTable[i] != NULL  )
		{
			Bucket* cur = hashTable[i];
			while (cur != NULL)
			{
				std::cout << "Ű: [" << i << "] �̸�: [" << cur->data->name << "]\n";
				cur = cur->next;
			}
		}
	}
}

int main()
{
	// �ؽ�
	// �޸� ���� �Ҹ� ũ����, ������ ó���� �ſ� ���� �ӵ��� ����
	
	// ���� ����
	// Ư�� ���� ������ �ؽ� �Լ��� ���� key���� ���ϰ�, key���� ������� ����
	// Ư�� value�� ã���� �ϸ� key�� ���� ���� ����

	// �ؽ� �浹
	// key �ߺ� �߻��� �浹�� �߻��ߴٰ� ǥ��
	// �浹 ó�� - 1. �浹 �߻� �׸��� �ٸ� ��ġ�� ���� (���������, ��������� ��)
	//             2. �ϳ��� ��Ŷ�� �������� �׸��� ���� (ü�̴�)
	
	// �ؽ�(Hashing)
	// ��������(Division Method)�� ���� ���� Ȱ�� -> �Է� ���� ���̺��� ũ��� ���� ���Ӵϸ� key�� Ȱ��

	// ���������
	// ����: ������ ���� ������ �����ͳ��� �����Ǵ� ���� ���� ������ �߻�
	Student** hashTable = new Student * [TABLE_SIZE];
	Init(hashTable);

	for (int i = 0; i < INPUT_SIZE; i++)
	{
		Student* student = new Student;
		student->id = rand() % 1000000;
		sprintf(student->name, "���%d", student->id);
		if (Search(hashTable, student->id) == -1)
		{
			int index = FindEmpty(hashTable, student->id);
			Add(hashTable, student, index);
		}
	}

	Show(hashTable);
	Destructor(hashTable);

	// ���������
	// ����������� ����������, Ű���� ������ �� ���� �������� ���ؼ� �ִ� ���
	// ���̺��� ���� ���� �Ǹ� ���̺��� ũ�⸦ Ȯ���� �ؽ� ���̺��� ����

	// ü�̴�
	// ���� ����Ʈ�� Ȱ���� Ư�� Ű�� ������ �׸���� �����Ͽ� ����
	Bucket** cHashTable = new Bucket*[TABLE_SIZE];
	init(cHashTable);

	for (int i = 0; i < INPUT_SIZE; i++)
	{
		Student* student = new Student;
		student->id = rand() % 1000000;
		sprintf(student->name, "���%d", student->id);
		if (!isExist(cHashTable, student->id))
		{
			add(cHashTable, student);
		}
	}

	show(cHashTable);
	destructor(cHashTable);

	return 0;
}