#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;

unordered_map<int, vector<int>> adj;
stack<int> stk;
vector<bool> visited = {};

void dfs(int node) {
	vector<int> arr = adj[node];
	cout << node << endl;
	visited[node] = true;
	if(stk.size() == 0) {
		return;
	} else {
		
		bool allVisited = true;
		for(int i = 0; i < arr.size(); i++) {
			if(visited[arr[i]] == false) {
				
				allVisited = false;
				stk.push(arr[i]);
				dfs(arr[i]);
				
			} 
		}	
		if(allVisited) {
			stk.pop();
		}
	}
	
	
}

int main() {
	int n, m;
	cin >> n >> m;
	
	for(int i = 0 ; i <= n; i++) {
		visited.push_back(false);
	}
	
	for(int i = 0; i < m; i++) {
		int c1, c2;
		cin >> c1 >> c2;
		
		adj[c1].push_back(c2);
		adj[c2].push_back(c1);
	}
//	root
	int components = 0;
	vector<int> paths;
	for(int i = 1; i <= visited.size() - 1; i++) {
		if(visited[i] == false) {
			stk.push(i);
			paths.push_back(i);
			dfs(i);
			components++;
		}
	}
	cout << components - 1 << endl;
	for(int i = 0; i < paths.size() - 1; i++) {
		cout << paths[i] << ' ' << paths[i+1] << endl;
	}
}
