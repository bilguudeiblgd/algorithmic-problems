#include<iostream>
#include<string>
#include<algorithm>

using namespace std;

void solve() {
    long long n;
    cin >> n;
    long long start = 0;
    long long end = 0;
    long long mul = 1;
    long long count = 1;
    long long interval_e = 1;
    long long interval_s = 0;
    // find out where the N is
    // n - x1x2x3x4
    // 1 - 123456789
    // 2 - 10111213...
    // 3 - 100101102...
    // if we know n then it'll be easier to solve the problem
    while(interval_e <= n) {
        start = mul;
        end = mul * 10;
        interval_s = interval_e;
        interval_e = interval_s + (end - start) * count;
        // cout << interval_s << " " << interval_e << endl;
        mul *= 10;
        count++;
    }
    count--;
    long long from_start = (n - interval_s) / count;
    // cout << "from start: "  << from_start << endl;
    long long number = from_start + start;
    long long digit = (n - interval_s) % count;
    // cout << "number: " << number << endl;
    string num_str = "";
    while(number) {
        num_str.push_back((number % 10) + '0');
        number /= 10;
    }
    reverse(num_str.begin(), num_str.end());
    // cout << "str_num: " << num_str << endl;
    // cout << "digit: " << digit << endl;
    cout << num_str[digit] << endl;
}

int main() {
    int t;
    cin >> t;
    for(int i = 0; i < t; i++) {
        solve();        
    }    
}