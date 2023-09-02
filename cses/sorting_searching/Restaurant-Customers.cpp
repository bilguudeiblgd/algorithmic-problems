#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
#include<utility>
using namespace std;
 
 
int main() {
    int n;
    cin >> n;
 
    vector<pair<int, int> > intervals;
    
    for(int i = 0; i < n; i++) {
        int start, end;
        cin >> start >> end;
        intervals.push_back({start, 1});
        intervals.push_back({end, -1});
    }
    sort(intervals.begin(), intervals.end());
    int currPpl = 0;
    int maxPpl = 0;
    for(int i = 0; i < n * 2; i++) {
        currPpl += intervals[i].second;
        maxPpl = max(currPpl, maxPpl);
    }
    cout << maxPpl << endl;
}