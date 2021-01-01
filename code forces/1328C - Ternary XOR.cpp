#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <math.h>
#include <string>

void solve()
{
	int n;
	std::cin >> n;

	char* a = new char[n + 1]();
	char* b = new char[n + 1]();

	int i = 0;
	for (i; i < n; i++)
	{
		char c;
		std::cin >> c;

		if (c == '2')
		{
			a[i] = b[i] = '1';
		}
		else if (c == '0')
		{
			a[i] = b[i] = '0';
		}
		else if (c == '1')
		{
			a[i] = '1';
			b[i] = '0';
			i++;
			break;
		}
	}

	for (i; i < n; i++)
	{
		char c;
		std::cin >> c;
		a[i] = '0';
		b[i] = c;
	}

	std::cout << a << "\n" << b << "\n";
}

int main()
{
	int t;
	std::cin >> t;
	
	while (t--)
	{
		solve();
	}

	return 0;
}