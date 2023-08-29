#include<iostream>
#include<vector>
#include<string>
#include<unordered_map>
struct Book{
    int cost;
    int pages;
};

using namespace std;

unordered_map<string, int> dp;

int findMax(vector<Book> &arr, int n, int index, int pages, int money, string & state) {
    // cout << state << " -> " << " pages: " <<pages << " | money: "<< money <<  endl;
    // cout <<  "index: " << index << " = " << " n: " << n  << endl;
    if(index == n) {
        // cout << "return" << endl;
        return pages;
    }
    
    if(dp.find(state) != dp.end()) {

        cout << "state exists: " << " state:" << state << " " <<dp.at(state) <<  endl;
        return dp[state];
    }
    dp[state] = pages;
    for(int i = index; i < n; i++) {
        if(money - arr[i].cost >= 0 && state[i] != '1') {
            state[i] = '1';
            dp[state] = max(dp[state],findMax(arr, n, i+1, pages + arr[i].pages, money - arr[i].cost, state));
            state[i] = '0';
        }
    }
    // return dp[state] = max_value;
    return dp[state];
}

int main() {
    int n, m;
    cin >> n >> m;
    vector<Book> arr;
    for(int i = 0; i < n; i++) {
        Book tmp;
        cin >> tmp.cost;
        arr.push_back(tmp);
    }
    for(int i = 0; i < n; i++) {
        cin >> arr[i].pages;
    }
    string state;
   
    for(int i = 0; i < n; i++) {
        state.push_back('0');
    }
    cout << findMax(arr,n, 0,0,m,state) << endl;
}