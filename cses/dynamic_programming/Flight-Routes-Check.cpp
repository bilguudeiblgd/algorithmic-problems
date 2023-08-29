#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<unordered_map>

using namespace std;

unordered_map<int, vector<int> > graph;
unordered_map<int, vector<int> > canReach;

bool visited[100000];

void dfs(int current, vector<int>& covered) {
    for(int cities : graph[current]) {
        if(!visited[cities]) {
            covered.push_back(cities);
            for(int covered_cities : covered) {
                canReach[covered_cities].push_back(cities);
            }
        }
    }
}

int main() {
    int n, m;
    cin >> n >> m;
    for(int i = 0; i < m; i++) {
        int orig, dest;
        cin >> orig >> dest;
        graph[orig].push_back(dest);
    }
    vector<int> covered;
    dfs(1, covered);

}