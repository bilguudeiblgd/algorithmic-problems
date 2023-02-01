#include<iostream>
#include<vector>
#include<algorithm>
#include<cmath>
#include<stack>
#include<unordered_map>

using namespace std;

int counter = 0;
typedef long long ll;


int main() {
    ll n;
    ll zeros = 0;
    cin >> n;
    // 5 is the key here. 5 *2 would be 10 and obviously 10 with anything will be the same.
    // Observation here is that 25 will bring up 2 trailing zeros 25 * 8 = 100.
    // 100 is also 25's multiple so. We can just count how many 5s, 25s, 125s, there is...
    int cnt = 1;
    ll dd = 0;
    ll mul1 = 25;
    ll mul2 = 100;
    zeros += (n / 5);
    while(mul1 <= n) {
        // cout << n / mul1 << endl;
        zeros += n / mul1;
        mul1 *= 5;
    }
    // while(mul2 <= n) {
    //     cout << n / mul2 << endl;
    //     zeros += n / mul2;
    //     mul2 *= 10;
    // }

    cout << zeros << endl;
}
