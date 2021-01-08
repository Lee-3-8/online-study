#include <iostream>

int main()
{
	int t;
	std::cin >> t;
	while (t--)
	{
		int n;
		std::cin >> n;

		bool c = true;
		int bp = 0, bc = 0;
		int np, nc;

		for (int i = 0; i < n; i++)
		{
			std::cin >> np >> nc;
			if (!(np >= nc && np >= bp && nc >= bc))
				c = false;
			if (np - bp < nc - bc)
			{
				c = false;
			}
			bp = np; bc = nc;
		}

		if (c) std::cout << "YES\n";
		else std::cout << "NO\n";
	}
	
	return 0;
}