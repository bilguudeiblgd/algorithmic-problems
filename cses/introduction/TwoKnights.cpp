#include<iostream>

using namespace std;
void solve(long long n) {
    // result = all total placement of 2 knights - total placement where 2 knights are attacking each other

    // Total
    // for first knight, it's just n*n
    // for second knight, it's n*n-1
    // so we now have (n*n * (n*n-1))
    // now we need to remove repetitions (since we don't have name for each knight, bob or george)
    // in the formula above, 1,3 and 3,1 is counted twice. Thus divide by two
    // total = (n*n * (n*n-1))/2
    
    // Attacking position
    // This one is tricky but formulating this problem to "how many variatians to place 2x3 and 3x2 blocks in n*n square"
    // Let's start with 2x3 and imagine horizontal case. Then it's n-2
    // vertical case is n-1 
    // so (n-1)*(n-2). It's also the vice versa for 3x2 so we now get 2*(n-1)(n-2)
    // since in each 2x3 and 3x2 block there's 2 attacking position (if u don't get it, draw it!!!)
    // so last formulla for attacking position is 4*(n-1)(n-2)
    
    // result =  ((n*n*(n*n-1))/2) - (4*(n-1)*(n-2))
    long long total = ((n*n*(n*n-1))/2);
    total -= (4*(n-1)*(n-2));
    printf("%lld\n",total);
}
int main () {

    long long n;
    cin >> n;
    for(long long i = 1; i <= n; i++) {
        solve(i);
    }
}