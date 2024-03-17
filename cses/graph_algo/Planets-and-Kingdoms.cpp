#include <iostream>
#include <vector>
#include <unordered_map>
#include <stack>
#include <queue>
#include <vector>
#include <algorithm>

using namespace std;

unordered_map<int, vector<int>> G;
unordered_map<int, vector<int>> rG;


void dfs1(int node, vector<int> & visited, stack<int> & s) {
  visited[node] = true;
  for(const int neigh : rG[node]) {
    if(visited[neigh]) continue;
    dfs1(neigh, visited, s);
  }
  s.push(node);
}

void step1(int n, stack<int> & s) {
  vector<int> visited(n+1, false);
  for(int i = 1; i <= n; i++) {
    if(!visited[i])
      dfs1(i, visited, s);
  }
}
void dfs2(int node, int groupNum, vector<int> & scc) {
  // stack for own dfs
  stack<int> s;
  
  s.push(node);
  while(!s.empty()) {
    int cur = s.top(); s.pop();
    scc[cur] = groupNum;
    for(const int neigh : G[cur]) {
      // if not assigned to group
      if(scc[neigh] == -1 ) {
        s.push(neigh);
      }
    }
  }
}

int main() {
  // Main idea is to find SCC in the graph
  // Algorithm used will try to find sinks and remove it from graph first
  // The way to do that is to traverse the reversed graph and push items into stack
  // It works as of the principle, source will always go out last
  // G -> sink = GT -> source
  int n,m;
  cin >> n >> m;
  
  int e1, e2;
  for(int i = 0; i < m; i++) {
    cin >> e1 >> e2;
    G[e1].push_back(e2);
    rG[e2].push_back(e1);    
  }
  // cout << "Print graph" << endl;


  stack<int> s;
  // sending stack s as a output parameter
  step1(n, s);
  
  vector<int> scc(n+1, -1);
  int group = 0;
  while(!s.empty()) {
    int cur = s.top(); s.pop();
    if(scc[cur] == -1) {
      dfs2(cur, ++group, scc);
    }
  }
  cout << group << endl;
  for(int i = 1; i <= n; i++) {
    cout << scc[i] << " ";
  }
  cout << endl;
}