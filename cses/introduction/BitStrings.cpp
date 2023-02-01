#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;


#define MOD 1000000007
int counter = 0;
unordered_map<int, int> table;


int main() {
	long long n;
    cin >> n;
    long long ans = 1;
    for(int i = 0; i < n; i++) {
        ans = (ans * 2) % MOD;
    }
    cout << ans << endl;
}
