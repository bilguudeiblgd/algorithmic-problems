#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
using namespace std;



int main() {
    long long n, target;
    cin >> n >> target;
    long long prefix_arr[n];
    unordered_map<long long, long long> map;
    for(long long i = 0; i < n; i++) {
        cin >> prefix_arr[i];
        if(i != 0) {
            prefix_arr[i] += prefix_arr[i-1];
        }
        
    }

    long long count = 0;
    map[0] = 1;
    for(long long i = 0; i < n; i++) {
        long long look_for = prefix_arr[i] - target;
        count += map[look_for];
        map[prefix_arr[i]]++;        
    }
    cout << count << endl;

    // printf("")
        
}
