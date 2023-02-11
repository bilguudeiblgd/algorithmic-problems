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

    for(long long i = 1; i <= target; i++) {
        for(long long j = 0; j < n; j++) {
            if(i - coins[j] >= 0) 
                dp[i] += (dp[i-coins[j]]) % MOD;
        }
    }
    cout << (dp[target] % MOD) << endl;
}
