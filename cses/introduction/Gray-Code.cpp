#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;

unordered_map<string, bool> dp;

void rec(string str, int n, size_t len, char pre_ch) {
    cout << str << endl;
    dp[str] = true;
    if(len == pow(2,n) ) {
        return;
    }
    for(int i = 0; i < n; i++) {
        
        if(str[i] == '0') {
            str[i] = '1';
            if(dp.find(str) != dp.end()) {
                str[i] = '0';
                continue;
            }
        } 
        else {
            str[i] = '0';
            if(dp.find(str) != dp.end()) {
                str[i] = '1';
                continue;
            }
        }
        return rec(str, n, len+1, pre_ch);
    }
}

int main() {
	int n;
    cin >> n;
    string str;
    for(int i = 0; i < n; i++) {
        str.push_back('0');
    }
    // int count = pow(2,n);
    rec(str, n, 0, 2);
}
