#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

vector<int> s;
vector<int> p;

vector<bool> table;
int n;
long long search(int k) {

	if(k == n) {
		long long sum1 = 0;
		for(int i = 0; i < p.size(); i++) {
			
			sum1 += p[i];
		}
		
		
		long long sum2 = 0;
		for(int i = 0; i < n; i++) {
			if(table[i] == false) {
				sum2 += s[i];
			}
		}
	
		return abs(sum2 - sum1);
	}
	else {
		long long min1, min2;
		min1 = search(k+1);
		p.push_back(s[k]);
		table[k] = true;
		min2 = search(k+1);
		p.pop_back();
		table[k] = false;
		return min(min1, min2);
	}
}

int main() {
	
	cin >> n;
	for(int i = 0; i < n; i++) {
		int element;
		cin >> element;
		s.push_back(element);
		table.push_back(false);
	}

	cout << search(0);
	
}
