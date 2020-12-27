#include <iostream>

void solve()
{
    int n, x;
    std::cin >> n >> x;

    int* a = new int[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    int numEven = 0;
    int numOdd = 0;
    for (int i = 0; i < n; i++)
    {
        if (a[i] % 2 == 0) numEven++;
        else numOdd++;
    }

    bool possible = false;
    int o = x;
    int e = 0;
    while (!possible)
    {
        if (o <= numOdd && e <= numEven)
        {
            if (o % 2 == 1) possible = true;
        }

        o--; e++;
        if (o < 0) break;
    }

    if (possible) std::cout << "YES\n";
    else std::cout << "NO\n";
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