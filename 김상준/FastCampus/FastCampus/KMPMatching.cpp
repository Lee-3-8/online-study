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
	// 단순 비교 문자열 매칭 - 처음부터 끝까지 계속 비교하는 알고리즘, O(NM)의 시간복잡도

	// KMP 문자열 매칭 - O(N + M)의 시간 복잡도
	// 접두사와 접미사를 활용해 매칭을 수행
	// 찾고자하는 패턴 문자열의 길이에 따른 접두사와 접미사가 일치하는 최대 길이를 구함 -> MakeTable
	KMP(parent, pattern);
}