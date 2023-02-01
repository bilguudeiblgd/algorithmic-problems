#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<set>
using namespace std;


string s;
string b = "";
vector<bool> table;
set<string> match;
int counter = 0;
void permut(int n) {
	if(n == s.size()) {
	
		match.insert(b);
		
		counter++;
		return;
	}
	else {
		for(int i = 0; i < s.size(); i++) {
			if(table[i] == false) {
				b[n] = s[i];
				table[i] = true;
				permut(n+1);
				table[i] = false;
			}
		
		}
	}
}

int main() {
	
	getline(cin, s);
	b = s;
	for(int i = 0; i < s.size(); i++) {
		table.push_back(false);
	}
	permut(0);
	cout << match.size() << endl;
	for(auto it = match.begin(); it != match.end(); it++) {
		cout << *it << endl;
	}


	
}
