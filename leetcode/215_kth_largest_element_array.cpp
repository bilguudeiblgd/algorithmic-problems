#include<iostream>

int main() {

     
}

class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // quick select, the same as n - k smallest element
        k = nums.size() - k + 1;
        return quickSelect(nums, k);
    }
    int quickSelect(vector<int> & nums, int k) {
        // choose random point?
        vector<int> L;
        vector<int> M;
        vector<int> R;

        int m = nums[nums.size() / 2];

        for(const int & e : nums) {
            if(e == m) 
                M.push_back(e);
            else if(e < m)
                L.push_back(e);
            else
                R.push_back(e);
        }
        // edge cases if L or R is empty
        if(k <= L.size())
            return quickSelect(L, k);
        if(k - L.size() <= M.size())
            return M[M.size()];
        else 
            return quickSelect(R, k - L.size() - M.size());
    }
};
