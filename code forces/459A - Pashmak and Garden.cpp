#include <iostream>
using namespace std;

int main()
{
	int x1, x2, y1, y2;
	std::cin >> x1 >> y1 >> x2 >> y2;

	if (x2 - x1 == 0)
	{
		int l = abs(y2 - y1);
		std::cout << x1 + l << " " << y1 << " " << x2 + l << " " << y2 << "\n";
	}
	else if (y2 - y1 == 0)
	{
		int l = abs(x2 - x1);
		std::cout << x1 << " " << y1 + l << " " << x2 << " " << y2 + l << "\n";
	}
	else
	{
		if (abs(x2 - x1) != abs(y2 - y1)) { std::cout << -1 << "\n"; return 0; }
		std::cout << x1 << " " << y2 << " " << x2 << " " << y1 << "\n";
	}

	return 0;
}