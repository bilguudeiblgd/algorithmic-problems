#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;
#define MOD 1000000007

long long dp[2000000];

long long rec(long long sum) {
	if(sum == 0) {
		return 1;
	}
	if(sum < 0) {
		return 0;
	}
	if(dp[sum]) {
		return dp[sum];
	}
	for(int i = 1; i <= 6; i++)
		// if(sum - i >= 0) {
			dp[sum] = (dp[sum] + (rec(sum - i) % MOD)) % MOD;
	// }
	return (dp[sum] % MOD);
};


int main() {
	long long n;
	cin >> n;
	long long ans = rec(n);
	printf("%lld\n", ans);	
}
