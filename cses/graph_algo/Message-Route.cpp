#include<iostream>
#include<vector>
#include<unordered_map>
#include<stack>
#include<queue>
#include<vector>
#include<algorithm>

using namespace std;

int returnShortest(int n, unordered_map<int, vector<int>> & table, vector<int> & previous) {
    int start = 1;
    int end = n;
    vector<bool> visited(n+1, false);
    // Initiate BFS
    queue<int> q;
    vector<int> initial = {start};
    q.push(start);
    while(!q.empty()) {
        int cur = q.front();
        q.pop();
        
        const vector<int> & neighbors = table[cur];
        for(const int neigh : neighbors) {
            if(visited[neigh]) 
                continue;
            previous[neigh] = cur;
            visited[neigh] = true;
            if(neigh == end) {
                return 0;
            }
            q.push(neigh);
        }
    }
    return 1;
}

int main() {
    int n,m;
    cin >> n >> m;
    unordered_map<int, vector<int>> table;
    for(int i = 0; i < m; i++) {
        int com1, com2;
        cin >> com1 >> com2;
        if(table.find(com1) == table.end()) {
            table[com1] = vector<int>();
        }
        table[com1].push_back(com2);
        if(table.find(com2) == table.end()) {
            table[com2] = vector<int>();
        }
        table[com2].push_back(com1);

    }
    vector<int> previous(n+1, 0);

    int ans = returnShortest(n, table, previous);
    if(ans == 1) {
        cout << "IMPOSSIBLE" << endl;
        return 0;
    }

    // Backtrack
    vector<int> record;
    int cur = n;
    while(cur != 1) {
        record.push_back(cur);
        cur = previous[cur];
    }
    record.push_back(1);
    
    
    cout << record.size() << endl;
    for(int i = record.size() - 1; i >= 0; i--) {
        cout << record[i] << " ";
    }
    cout << endl;
    return 0;
}