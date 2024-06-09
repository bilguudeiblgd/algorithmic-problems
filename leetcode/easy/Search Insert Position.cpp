class Solution {
public:
    int searchInsert(vector<int>& nums, int target) {
      // Just a binary sort. If target is found, return the index
      // If not found, return the left index which is where to insert
        int left = 0;
        int right = nums.size() - 1;
        int mid = 0;
        while(left <= right) {
            mid = left + (right - left) / 2;
            if(target == nums[mid]) {
                return mid;
            }
            else if(target > nums[mid]) {
                left = mid + 1;
            }
            else {
                right = mid - 1;
            }
        }
        return left;
    }
};