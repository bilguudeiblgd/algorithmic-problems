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
	int index = 0;
	if(n < 4 && n != 1) {
		cout << "NO SOLUTION" << endl;
		return 0;
	}
	for(int i = 2; i <= n; i = i + 2) {
		arr[index] = i;
		cout << arr[index] << ' ';
		index++;
	}
	for(int i = 1; i <= n; i = i + 2) {
		arr[index] = i;
		cout << arr[index] << ' ';
		index++;
	}

	cout << endl;
}
