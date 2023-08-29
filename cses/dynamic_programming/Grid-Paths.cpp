#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;
#define MOD 1000000007

long long dp[1001][1001];


int main() {
	int n;
    cin >> n;
    vector<string> board;
    for(int i = 0 ; i < n ; i++) {
        string str;
        cin >> str;
        board.push_back(str);
    }
    dp[0][0] = 1;
    for(int i = 0; i < n; i++) {
        for(int j = 0 ; j < n; j++) {
            if(board[i][j] == '.') {
                if(i > 0 && board[i-1][j] == '.')
                    dp[i][j] += (dp[i-1][j] % MOD);
                if(j > 0 && board[i][j-1] == '.')
                    dp[i][j] += (dp[i][j-1] % MOD);
                dp[i][j] %= MOD;
            }
        }
    }
    if(board[n-1][n-1] == '*')
        cout << 0 << endl;
    else
        cout << dp[n-1][n-1] << endl;

}
