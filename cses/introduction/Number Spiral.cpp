#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;

void solve() {
	long long r, c;
	cin >> r >> c;
	long long k = max(r,c);
	
	long long sq2 = k * k;
	long long sq1 = (k-1) * (k-1);

	long long answer;
	if(c > r) {
		if(c % 2 == 0) {
			answer = sq1 + r;
		} else{
			answer = sq2 - r + 1;
		}
	} else {
		if(r % 2 == 0) {
			
			answer = sq2 - c + 1;
		} else{
			answer = sq1 + c;
		}
	}
	cout << answer << endl; 
}

int main() {
	int t; 
	cin >> t;
	for(int i = 0; i < t; i++) {
		solve();
	}

	cout << endl;
}
