#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;


bool closeEnough(int a, int b, int k) {
    if(abs(a-b) <= k)
        return true;
    else 
        return false;
}

int main () {
    int n,m,k;
    cin >> n >> m >> k;
    int p[n];
    int a[m];
    for(int i = 0; i < n; i++)
        cin >> p[i];
    for(int i = 0; i < m; i++)
        cin >> a[i];
    sort(p, p+n, greater<int>());
    sort(a, a+m, greater<int>());
    
   
    int i = 0, j = 0;
    int count = 0;
    while(i < n && j < m) {
        if(closeEnough(p[i], a[j], k)) {
            // cout << "matching: " << p[i] << ' ' << a[j] << endl;
            count++;
            i++;
            j++;
        }   
        else if(p[i] > a[j]) {
            i++;
        }
        else if(p[i] < a[j]) {
            j++;
        }
    }
    cout << count << endl;

}
