#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;



int main() {
	int n;
	cin >> n;
	int arr[n];
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr+n);
	int counter = 1;
	for(int i = 0; i < n - 1; i++) {
		if(arr[i] != arr[i+1]) {
			counter++;
		}
	}
	cout << counter;
}
