#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;
#define MOD 1000000007

int dp[2000000];
vector<int> coins;

int rec(int sum, int size) {
	if(sum == 0) {
		return 0;
	}
	if(sum < 0)
		return 2000000;
	
	if(dp[sum]) {
		return dp[sum];
	}
	dp[sum] = 2000000;
	for(int i = 0; i < size; i++) 
		if(sum - coins[i] >= 0) {
			dp[sum] = min (dp[sum], 1 + rec(sum - coins[i], size));
		}
	return dp[sum];
};


int main() {
	int n, target;
	cin >> n >> target;
	
	for(int i = 0; i < n; i++) {
		int e; cin >> e;
		coins.push_back(e);
	}
	int ans = rec(target, n);
	if(ans == 2000000) {
		printf("-1\n");
		return 0;
	}
	// for(int i = 0; i < target; i++) {
	// 	cout << dp[i] << ' ';
	// }
	// cout << endl;
	printf("%d\n", ans);	
}
