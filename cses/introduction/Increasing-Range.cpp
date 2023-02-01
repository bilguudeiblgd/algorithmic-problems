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
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	long long moves = 0;
	for(int i = 0; i < n - 1; i++) {
		if(arr[i+1] < arr[i]) {
			moves += arr[i] - arr[i+1];
			arr[i+1] += (arr[i] - arr[i+1]);
		} 
	}
	cout << moves << endl;
}
