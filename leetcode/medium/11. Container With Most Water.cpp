class Solution {
public:
    int maxArea(vector<int>& height) {
        int i = 0;
        int j = static_cast<int>(height.size()) - 1;
        int maxArea = 0;
        // 2 Pointers
        while (i < j) {
            maxArea = max( min(height[i], height[j]) * (j-i), maxArea);
            if(height[j] > height[i]) {
                i++;
            } else {
                j--;
            }
        }
        return maxArea;
    }
};