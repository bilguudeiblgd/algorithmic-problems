#include<iostream>


using namespace std;

int main() {
    int n,q;
    cin >> n >> q;
    long long prefixSum[n + 1];
    prefixSum[0] = 0;
    for(int i = 1; i <= n; i++) {
        long long pre = prefixSum[i-1];
        cin >> prefixSum[i];
        prefixSum[i] = prefixSum[i] + pre;
    }
   
    for(int i = 0; i < q; i++) {
        int a,b;
        cin >> a >> b;
        a--;
        cout << prefixSum[b] - prefixSum[a] << endl;
    }

}