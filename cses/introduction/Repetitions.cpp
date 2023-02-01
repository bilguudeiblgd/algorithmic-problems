#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;

int counter = 0;
unordered_map<int, int> table;


int main() {
	string s;
	cin >> s;
	int maxrep = 0;
	int counter = 1;
	for(int i = 0; i < s.size(); i++) {
		if(s[i] == s[i+1]) {
			counter++;
			
		} else{
			counter = 1;
		}
		maxrep = max(maxrep, counter);
	}
	cout << maxrep << endl;
	
}
