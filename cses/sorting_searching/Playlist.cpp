#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <utility>
#include <unordered_map>
using namespace std;
 
int main()
{
    int n;
    cin >> n;
    unordered_map<int, bool> table;

    int maxUnique = 0;
    int unique = 0;
    for (int i = 0; i < n; i++) {
        int elem; cin >> elem;
        if(!table[elem]) {

            unique++;
            maxUnique = max(unique, maxUnique);

            table[elem] = true;
        }
        else {
            table = unordered_map<int, bool>();
            unique = 1;
        }
    }
 
    cout << maxUnique<< endl;
}