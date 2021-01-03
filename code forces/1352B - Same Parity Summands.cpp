#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int n, k;
		std::cin >> n >> k;

		if (n % 2 == 1)
		{
			if (k % 2 == 0) std::cout << "NO\n";
			else if (k > n) std::cout << "NO\n";
			else
			{
				std::cout << "YES\n";
				for (int i = 0; i < k - 1; i++)
				{
					std::cout << 1 << " ";
					n--;
				}
				std::cout << n << "\n";
			}
		}
		else // n % 2 == 0
		{
			if (n == k)
			{
				std::cout << "YES\n";
				for (int i = 0; i < k; i++)
				{
					std::cout << 1 << " ";
				}
				std::cout << "\n";
			}
			else if (k > n / 2)
			{
				if (k % 2 == 0 && k < n)
				{
					std::cout << "YES\n";
					for (int i = 0; i < k - 1; i++)
					{
						std::cout << 1 << " ";
						n--;
					}
					std::cout << n << "\n";
				}
				else std::cout << "NO\n";
			}
			else
			{
				std::cout << "YES\n";
				for (int i = 0; i < k - 1; i++)
				{
					std::cout << 2 << " ";
					n -= 2;
				}
				std::cout << n << "\n";
			}
		}
	}

	return 0;
}