#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<queue>
#include<unordered_map>

using namespace std;



vector<int> colorGraph(int n, const unordered_map<int, vector<int>> & graph) {
    vector<int> colors(n, 0);
    vector<bool> visited(n, false);

    // for(size_t i = 0; i < colors.size(); i++) {
        // cout << colors[i] << " ";
    // }
    // cout << endl;

    for(size_t i = 0; i < n; i++) {
        
        if(!visited[i]) {
            queue<pair<int,int >> q;
            q.push(make_pair(i, 2));
            while(!q.empty()) {
                int cur = q.front().first;
                int prevCol = q.front().second;
                q.pop();
                int curCol = 0;
                if(prevCol == 2) {
                    curCol = 1;
                }
                else {
                    curCol = 2;
                }
                if(colors[cur] && colors[cur] != curCol)
                    return colors;

                colors[cur] = curCol;
                visited[cur] = true;
                if(graph.find(cur) == graph.end()) {
                    continue;
                }
                const vector<int> & neighbours = graph.at(cur);
                for(const int neigh : neighbours) {
                    if(colors[neigh] == curCol) {
                        return vector<int>(n,0);
                    }
                    if(!visited[neigh])
                        q.push(make_pair(neigh, curCol));
                }
            }
        }
    }
    return colors;
}

int main() {
    int n,m;
    int f1, f2;
    cin >> n >> m;
    unordered_map<int, vector<int> > graph;
    for(int i = 0; i < m; i++) {
        cin >> f1 >> f2;
        f1--; f2--;
        if(graph[f1].empty()) {
            graph[f1] = vector<int>();
        }
        graph[f1].push_back(f2);

        if(graph[f2].empty()) {
            graph[f2] = vector<int>();
        }
        graph[f2].push_back(f1);
    }
    vector<int> colors = colorGraph(n, graph);

    for(size_t i = 0; i < n; i++) {
        if(colors[i] == 0) {
            cout << "IMPOSSIBLE" << endl;
            return 0;
        }
    }

    for(size_t i = 0; i < n; i++) {
        cout << colors[i] << " ";
    }
    cout << endl;

}