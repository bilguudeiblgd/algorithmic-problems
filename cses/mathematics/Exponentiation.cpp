#include<iostream>


using namespace std;

const int MOD = 1000000007;

long long rec(long long base, long long exp) {
    if(exp == 1) {
        return base;
    }
    if(exp == 0) {
        return 1;
    }
    return rec((base * base) % MOD , exp / 2) * ((exp % 2 == 0 ? 1 : (base % MOD)) % MOD) % MOD ;
}

void solve() {
    long long a,b;
    cin >> a >> b;
    
    cout << rec(a,b) << endl;
}

int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        solve();
    }

}