#include<iostream>
#include<vector>
#include<string>
using namespace std;



int main() {
    int n;
    cin >> n;
    int arr[n + 1];
    arr[0] = 0;
    int order = 1;
    // Number to index mapping, then place them in a array, and whenever the index goes down, it's another round
    for(int i = 0; i < n; i++) {
        int num;
        cin >> num;
        arr[num] = order;
        order++;
    }
   
    int round = 1;
    for(int i = 1; i < n + 1; i++) {
        if(arr[i-1] > arr[i]) {
            round++;
        }
    }
    cout << round << endl;
}
