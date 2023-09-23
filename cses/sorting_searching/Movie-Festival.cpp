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
        intervals.push_back(make_pair(end,start));
    }
    // Sort by ending times
    sort(intervals.begin(), intervals.end());
    int ending = 0;
    int count = 0;
    for(int i = 0; i < n; i++) {
        if(ending <= intervals[i].second) {
            ending = intervals[i].first;
            count++;
        }
    }
   
    cout << count << endl;

}