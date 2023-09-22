#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;



int main() {
    int n;
    cin >> n;
    int arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    sort(arr, arr+n);

    if(n % 2 == 1) {
        int mid = arr[(n-1)/2];
        long long diff = 0;
        for(int i = 0; i < n; i++) {
            diff += abs(mid-arr[i]);
        }
        cout << diff << endl;
    }
    else {
        int mid1 = arr[(n-1)/2];
        int mid2 = arr[(n)/2];
        long long diff1 = 0;
        long long diff2 = 0;
        for(int i = 0; i < n; i++) {
            diff1 += abs(mid1-arr[i]);
            diff2 += abs(mid2-arr[i]);
        }
        cout << min(diff1, diff2) << endl;
    }
    return 0;
}
