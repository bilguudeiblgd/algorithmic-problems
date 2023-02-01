#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;
#define SIZE 2000000
vector<int> children[SIZE];
int subtree_size[SIZE];
int dfs(int cur) {
    if(children[cur-1].size() == 0) {
        return 0 ;
    } 
    if(subtree_size[cur-1] != 0) {
        return subtree_size[cur-1];
    }
    int count = 0;
    
    for(int child : children[cur-1]) {
        count += dfs(child) + 1;
    }
    return subtree_size[cur-1] = count;
}

int main() {
	int n;
    cin >> n;
    for(int i = 1; i < n; i++) {
        int parent;
        cin >> parent;
        children[--parent].push_back(i+1);
    }
    for(int i = 0; i < n; i++) {
        cout << dfs(i+1) << ' ';
    }
    cout << endl;
}
