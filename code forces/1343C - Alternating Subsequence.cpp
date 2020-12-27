#include <iostream>
#include <vector>

void solve()
{
    int n;
    std::cin >> n;
    long long* a = new long long[n];
    long long* b = new long long[n];
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    b[0] = a[0];
    int itr = 0; // iterator for array b
    for (int i = 1; i < n; i++)
    {
        if (a[i] * b[itr] > 0) // equal sign
        {
            if (a[i] > b[itr]) b[itr] = a[i];
        }
        else // different sign
        {
            b[++itr] = a[i];
        }
    }

    long long maxSum = 0;
    for (int i = 0; i <= itr; i++)
    {
        maxSum += b[i];
    }

    std::cout << maxSum << "\n";
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