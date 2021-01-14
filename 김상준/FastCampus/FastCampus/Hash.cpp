#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <string.h>
#include <time.h>
#define TABLE_SIZE 10007
#define INPUT_SIZE 5000

// ------------------------------- 선형 조사법 ------------------------------- //
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
			std::cout << "키: [" << i << "] 이름: [" << hashTable[i]->name << "]\n";
		}
	}
}

// ------------------------------- 체이닝 ------------------------------- //
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
				std::cout << "키: [" << i << "] 이름: [" << cur->data->name << "]\n";
				cur = cur->next;
			}
		}
	}
}

int main()
{
	// 해시
	// 메모리 공간 소모가 크지만, 데이터 처리는 매우 빠른 속도로 가능
	
	// 동작 과정
	// 특정 값이 들어오면 해시 함수를 거쳐 key값을 구하고, key값을 기반으로 저장
	// 특정 value를 찾고자 하면 key를 통해 접근 가능

	// 해시 충돌
	// key 중복 발생시 충돌이 발생했다고 표현
	// 충돌 처리 - 1. 충돌 발생 항목을 다른 위치에 저장 (선형조사법, 이차조사법 등)
	//             2. 하나의 버킷에 여러개의 항목을 저장 (체이닝)
	
	// 해싱(Hashing)
	// 나눗셈법(Division Method)을 가장 많이 활용 -> 입력 값을 테이블의 크기로 나눈 나머니를 key로 활용

	// 선형조사법
	// 단점: 유사한 값을 가지는 데이터끼리 밀집되는 집중 결합 문제가 발생
	Student** hashTable = new Student * [TABLE_SIZE];
	Init(hashTable);

	for (int i = 0; i < INPUT_SIZE; i++)
	{
		Student* student = new Student;
		student->id = rand() % 1000000;
		sprintf(student->name, "사람%d", student->id);
		if (Search(hashTable, student->id) == -1)
		{
			int index = FindEmpty(hashTable, student->id);
			Add(hashTable, student, index);
		}
	}

	Show(hashTable);
	Destructor(hashTable);

	// 이차조사법
	// 선형조사법과 유사하지만, 키값을 선택할 때 완전 제곱수를 더해서 넣는 방식
	// 테이블이 가득 차게 되면 테이블의 크기를 확장해 해시 테이블을 유지

	// 체이닝
	// 연결 리스트를 활용해 특정 키를 가지는 항목들을 연결하여 저장
	Bucket** cHashTable = new Bucket*[TABLE_SIZE];
	init(cHashTable);

	for (int i = 0; i < INPUT_SIZE; i++)
	{
		Student* student = new Student;
		student->id = rand() % 1000000;
		sprintf(student->name, "사람%d", student->id);
		if (!isExist(cHashTable, student->id))
		{
			add(cHashTable, student);
		}
	}

	show(cHashTable);
	destructor(cHashTable);

	return 0;
}