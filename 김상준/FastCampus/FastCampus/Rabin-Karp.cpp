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
	// ��� ī�� ���ڿ� ��Ī
	// �ؽø� Ȱ���ϴ� �˰���
	// ��������� O(N + M)�� �ð� ���⵵

	// �ƽ�Ű �ڵ� ����� �ؽ� �Լ��� �̿��Ͽ� ���ڿ��� ���� �ؽ� ���� ����
	// �ؽ� �Լ�: �� ������ �ƽ�Ű �ڵ� ���� 2�� �������� ���ʴ�� ���Ͽ� ���� ��, ���� ���� �ٸ� ���ڿ��̸� ���� �ٸ� �ؽ� ���� ���� - ������ �浹 ó���� �ʿ�
	RabinKarp(parent, pattern);
}