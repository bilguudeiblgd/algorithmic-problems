#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;
int op = 0;
void towerOfHanoi(int n, int start, int end) {
    if(n == 0)
        return;
    op++;
    int other = 6 - (start + end);
    towerOfHanoi(n-1, start, other);
    printf("%d %d\n", start, end);
    towerOfHanoi(n-1, other, end);
}

int main() {
    int n;
    cin >> n;
    cout << pow(2, n) -1 << endl; 
    towerOfHanoi(n,1,3);
    return 0;
}
