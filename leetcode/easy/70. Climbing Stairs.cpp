class Solution {
public:
    long long binomial(int n, int k) {
        // k = 1
        k = k < n - k ? k : n - k;

        long long res = 1;
        // i = 2, j = 1, 
        for(int i = n, j = 1 ; i >= n - k + 1; --i, ++j) {
            res *= i;
            res /= j;
        }
        return res;
    }
    int climbStairs(int n) {
        long long res = 0;
        for(int i = 0; i <= n / 2; i++) {
            res += binomial(n-i, i);
        }
        // f(x) = f(x-1) + x + ((x + 1) % 2) * x 
        return res;
    }
};
