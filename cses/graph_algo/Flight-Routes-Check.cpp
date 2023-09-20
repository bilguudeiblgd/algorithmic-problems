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
    stk.push(node);
	

    
    while(!stk.empty()) {

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
	}
    // If a node has 0 edge going outwards, then it has no connection
    int example[2];
    for(auto it : adj) {
        if(it.second.size() == 0) {
            example[0] = it.first;
            if(it.first == 1) {
                example[1] = 2;
            }
            if(it.first == n) {
                example[1] = it.first-1;
            }
            cout << "NO" << endl;
            cout << example[0] << " " << example[1];
            return 0;
        }
    }
    
    // If there's a separate components, then we have no way of getting 1 component to another
	vector<vector<int> > components;
	for(int i = 1; i <= visited.size() - 1; i++) {
        vector<int> component;
		if(visited[i] == false) {
			component.push_back(i);
			dfs(i);
		}
        components.push_back(component);
	}
	cout << "Components count: " << components.size() << endl;
    if(components.size() <= 1) {
        cout << "YES" << endl;
        return 0;
    }
    cout << "NO" << endl;
    cout << 
    
    return 0;
}
