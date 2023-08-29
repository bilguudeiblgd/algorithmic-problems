#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>

using namespace std;

int main() {
	int n, w;
	cin >> n >> w;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n, greater<int>());
    
    int count = 0;
    int current = w;
    int j = n - 1;
    int i = 0;
    while(i <= j) {
        // cout << "w: " << current << endl;
        current = w;
        if(current - arr[i] - arr[j] >= 0) {
            i++;
            j--;
            count++;
            continue;
        }
        if(current - arr[i] >= 0) {
            i++;
            count++;
            continue;
        }
    }
    cout << count << endl;
}
