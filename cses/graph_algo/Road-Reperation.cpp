#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;
int main()
{
	int n, m;
	cin >> n >> m;
	int u, v, e;
	vector<int> mapping(n + 1);
	vector<pair<int, int>> heap (n+1);
	// initialize
	for(int i = 1; i <= n; i++) {
		mapping[i] = i;
		heap[i] = make_pair(i, INT32_MAX);
	}
	vector < vector<pair<int, int>>> graph(n + 1);
	for (size_t i = 0; i < m; i++)
	{
		cin >> u >> v >> e;
		graph[u].push_back(make_pair(v, e));
		graph[v].push_back(make_pair(u, e));
	}

	// implement Jarnik algorithm
	
	
}
