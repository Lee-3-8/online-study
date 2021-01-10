#include <iostream>
#include <stdlib.h>
#include <string.h>
#include <string>

std::string parent = "acabacdabacdab"; //acabacdabacdab
std::string pattern = "abacdab"; //abacdab

int* MakeTable(std::string pattern)
{
	int patternSize = pattern.size();
	int* table = new int[patternSize];
	for (int i = 0; i < patternSize; i++)
	{
		table[i] = 0;
	}
	int j = 0;
	for (int i = 1; i < patternSize; i++)
	{
		while (j > 0 && pattern[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (pattern[i] == pattern[j])
		{
			table[i] = ++j;
		}
	}
	return table;
}

void KMP(std::string parent, std::string pattern)
{
	int* table = MakeTable(pattern);
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int j = 0;
	for (int i = 0; i < parentSize; i++)
	{
		while (j > 0 && parent[i] != pattern[j])
		{
			j = table[j - 1];
		}
		if (parent[i] == pattern[j])
		{
			if (j == patternSize - 1)
			{
				std::cout << "Succeeded at index " << i - j << "\n";
				j = table[j];
			}
			else
			{
				j++;
			}
		}
	}
}

int main()
{
	// �ܼ� �� ���ڿ� ��Ī - ó������ ������ ��� ���ϴ� �˰���, O(NM)�� �ð����⵵

	// KMP ���ڿ� ��Ī - O(N + M)�� �ð� ���⵵
	// ���λ�� ���̻縦 Ȱ���� ��Ī�� ����
	// ã�����ϴ� ���� ���ڿ��� ���̿� ���� ���λ�� ���̻簡 ��ġ�ϴ� �ִ� ���̸� ���� -> MakeTable
	KMP(parent, pattern);
}