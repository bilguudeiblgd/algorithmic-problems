#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<utility>
#include<stack>
#include<set>
#include<unordered_map>

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> parents;
int startV, endV;
int n, m;

bool dfs(int node, int previous) {

    visited[node] = true;
    parents[node] = previous;
    for(int neighbor : adj[node]) {
        if(previous == neighbor)
            continue;
        if(visited[neighbor]) {
            startV = neighbor;
            endV = node;
            return true;
        }
        else {
            if(dfs(neighbor, node))
                return true;
        }
    }
    return false;
}
bool visitAll() {
    for(int i = 1; i <= n; ++i)
	{
		if(!visited[i])
			if(dfs(i,-1)) return true;
	}
	return false;
}

int main() {
    cin >> n >> m;
    for(int i = 0; i <= n; i++) {
        adj.push_back(vector<int>());
    }
    for(int i = 0; i <= n; i++) {
        visited.push_back(false);
    }
    for(int i = 0; i <= n; i++) {
        parents.push_back(0);
    }
    for(int i = 0; i < m; i++) {
        int e1, e2;
        cin >> e1 >> e2;
        adj[e1].push_back(e2);
        adj[e2].push_back(e1);
    }

    if(!visitAll()) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }
    
    vector<int> ans;
    int cur = endV;
    ans.push_back(startV);
    while(cur != startV) {
        ans.push_back(cur);
        cur = parents[cur];
    }
    ans.push_back(startV);
    cout << ans.size() << endl;
    for(int i = ans.size() - 1; i >= 0; i--) {
        cout << ans[i] << " ";
    }
    cout << endl;
    return 0;
}
