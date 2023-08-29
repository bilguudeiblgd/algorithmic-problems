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
	int n, target;
    cin >> n >> target;
    for(int i = 0; i < n; i++) {
        int e;
        cin >> e;
        coins.push_back(e);
    }
    // Knapsack dp
    dp[0] = 1;

    for(long long i = 0; i < n; i++) {
        for(long long j = 1; j <= target; j++) {
            if(j - coins[i] >= 0) 
                dp[j] += (dp[j-coins[i]]) % MOD;
                dp[j] %= MOD;
        }
    }
    // for(int i = 0; i < target; i++) {
    //     cout << dp[i] << ' ';
    // }
    // cout << endl;
    cout << dp[target] << endl;
}
