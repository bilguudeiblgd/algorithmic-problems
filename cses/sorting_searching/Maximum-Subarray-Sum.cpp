#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main() {
    int n;
    cin >> n;
    long long arr[n];
    for(int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    long long sum = arr[0], best = arr[0];
    for(int i = 1; i < n; i++) {
        sum = max(sum + arr[i], arr[i]);
        best = max(sum, best);
    }
    cout << best << endl;
        
}
