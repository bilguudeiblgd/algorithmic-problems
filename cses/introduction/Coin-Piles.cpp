#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;

void solve() {
    long long l,r ;
    cin >> l >> r;
    // { 2x + y = l }
    // { x + 2y = r }
    // if this SLE has a positive integer solution, then possible,
    //  otherwise no.
    long long x, y;
    y = (l - 2 * r);
    if(y % 3 != 0) {
        cout << "NO" << endl;
        return;
    }
    y = y / (-3);
    if(y < 0) {
        cout << "NO" << endl;
        return;
    }

    x = 2 * l - 4 * r;
    if(x % 3 != 0) {
        cout << "NO" << endl;
        return;
    }
    x = x / (3);
    x = r + x;
    if(x < 0) {
        cout << "NO" << endl;
        return;
    }

    cout << "YES" << endl;
}

int main() {
	int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        solve();
    }
}
