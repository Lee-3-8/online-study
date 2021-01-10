#include <iostream>
#include <vector>
using namespace std;

int res = 0;
int visit[100001];

void check(vector<int>* root, int* cat, int index, int numCat, int m)
{
	visit[index] = 1;
	if (cat[index] == 0) numCat = 0;
	else numCat++;
	if (numCat > m) return;
	if (root[index].size() == 1 && index != 1) { res++; return; }

	for (auto itr = root[index].begin(); itr != root[index].end(); itr++)
	{
		if (!visit[*itr])
		{
			check(root, cat, *itr, numCat, m);
		}
	}
}

int main()
{
	int n, m;
	std::cin >> n >> m;

	int* cat = new int[n + 1];
	for (int i = 0; i < n; i++)
	{
		std::cin >> cat[i + 1];
	}

	vector<int>* adj = new vector<int>[n + 1];
	for (int i = 0; i < n - 1; i++)
	{
		int from, to;
		std::cin >> from >> to;
		adj[from].push_back(to);
		adj[to].push_back(from);
	}

	check(adj, cat, 1, 0, m);

	std::cout << res;

	return 0;
}