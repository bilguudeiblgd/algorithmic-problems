#include<iostream>
 
 
using namespace std;
 
const int MOD = 1000000007;
 
long long rec(long long base, long long exp) {
    
    cout << "base: " << base << endl;
    cout << "exp: " << exp << endl;

    if(exp == 1) {
        return base;
    }
    if(exp == 0) {
        return 1;
    }
    // Fermat's little theorem
    if(exp >= MOD) {
        return rec(base, exp / MOD) * rec(base, exp % MOD);
    }
    return (rec((base * base) % MOD, exp / 2) % MOD * (exp % 2 == 0 ? 1 : base) % MOD) % MOD;
}
 
void solve() {
    long long a,b,c;
    cin >> a >> b >> c;
    
    cout << rec(a, rec(b,c)) << endl;
}
 
int main() {
    int n;
    cin >> n;
    for(int i = 0; i < n; i++) {
        solve();
    }
 
}