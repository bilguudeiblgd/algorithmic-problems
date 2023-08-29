#include<iostream>
#include<vector>
#include<string>
#include<set>
#include<algorithm>
using namespace std;


int main () {
    int n,m;
    cin >> n >> m;
    multiset<int> t;
    int tmp;
    for(int i = 0; i < n; i++) {
        cin >> tmp; t.insert(tmp);

    }
    
    // for(auto it = t.begin(); it != t.end(); it++) {
    //     cout << *it << " ";
    // }
    // cout << endl;
    for(int i = 0; i < m; i++) {
        cin >> tmp;
        auto it = t.upper_bound(tmp);
        if(it == t.begin()) {
            cout << -1 << "\n";
        }
        else {
            cout << *(--it) << "\n";
            t.erase(it);
        }
    }
    

}
