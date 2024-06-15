class Solution {
public:
    void initTable(int table[], int value) {
        for(int i = 0; i < 256; i++) {
            table[i] = value;
        }
    }
    int lengthOfLongestSubstring(string s) {
        // Letters currently existing in the sliding window
        int table[256];
        initTable(table, -1);

        int left = 0;
        int right = 0;
        int maxCount = 0;
        int count = 0;
        // Sliding window
        while(right < s.size()) {
            // If the letter doesn't exist
            if( table[ s[right]] == -1 ) {
                
                table[ s[right]] = right;
                // cout << s[right]  <<" adding to table in " << s[right]<< endl;
                right++;
                count++;
                maxCount = max(count, maxCount);
            }
            // If the letter does exist
            else if( table[ s[right]] != -1 ) {
                // We move the left higher than index of the previous occurence of that letter and repeat
                while(left <= table[ s[right]]) {
                    // They are not in the sliding window
                    table[ s[left++]] = -1;
                }
                // Update the position of the letter we found
                table[ s[right]] = right;
                // Count is just the sliding window
                // Count itself is there
                count = right - left + 1;
                maxCount = max(count, maxCount);
                right++;
            }
        }
        return maxCount;
        
    }
};
