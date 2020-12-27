#include <iostream>
#include <vector>

void solve()
{
    int n, k;
    std::cin >> n >> k;

    int a = k % (n - 1); // 7 % 2 = 1
    int b = k / (n - 1); // 7 / 2 = 3

    if (a == 0)
    {
        std::cout << n * b - 1 << "\n";
    }
    else
    {
        std::cout << n * b + a << "\n";
    }
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