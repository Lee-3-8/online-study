#include <iostream>
#include <string>

std::string parent = "acabacdabac";
std::string pattern = "abacdab";

void Check(std::string parent, std::string pattern, int start)
{
	int found = 1;
	int patternSize = pattern.size();
	for (int i = 0; i < patternSize; i++)
	{
		if (parent[start + i] != pattern[i])
		{
			found = 0; 
			break;
		}
	}
	if (found)
	{
		std::cout << "Successful match at index " << start;
	}
}

void RabinKarp(std::string parent, std::string pattern)
{
	int parentSize = parent.size();
	int patternSize = pattern.size();
	int parentHash = 0, patternHash = 0, power = 1;
	for (int i = 0; i <= parentSize - patternSize; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < patternSize; j++)
			{
				parentHash += parent[patternSize - 1 - j] * power;
				patternHash += pattern[patternSize - 1 - j] * power;
				if (j < patternSize - 1) power *= 2;
			}
		}
		else
		{
			parentHash = 2 * (parentHash - parent[i - 1] * power) + parent[patternSize - 1 + i];
		}
		if (parentHash == patternHash)
		{
			Check(parent, pattern, i);
		}
	}
}

int main()
{
	// 라빈 카프 문자열 매칭
	// 해시를 활용하는 알고리즘
	// 평균적으로 O(N + M)의 시간 복잡도

	// 아스키 코드 기반의 해시 함수를 이용하여 문자열에 대한 해시 값을 구함
	// 해시 함수: 각 문자의 아스키 코드 값에 2의 제곱수를 차례대로 곱하여 더한 값, 보통 서로 다른 문자열이면 서로 다른 해시 값이 나옴 - 하지만 충돌 처리가 필요
	RabinKarp(parent, pattern);
}