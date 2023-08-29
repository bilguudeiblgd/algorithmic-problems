#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;
#define MOD 1000000007

long long dp[1000001];

vector<int> coins;



int main() {
	int n;
    cin >> n;

    // dp[0] = 1;

    for(int i = 1; i <= n; i++) {
        vector<int> digits;
        int tmp = i;
        dp[i] = INT32_MAX;
        while(tmp) {
            int digits = tmp % 10;
            dp[i] = min(dp[i],dp[i-digits] + 1);
            tmp /= 10;
        }
    }
    // for(int i = 0; i < n; i++) {
    //     cout << dp[i] << " ";
    // }
    // cout << endl;
    cout << dp[n] << endl;
}
