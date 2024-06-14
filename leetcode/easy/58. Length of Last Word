class Solution {
public:
    int lengthOfLastWord(string s) {
        int res = 0;
        int index = s.size() - 1;
        // Skip whitespace
        while(index >= 0 && s[index] == ' ') {
            index--;
        }
        // Count the length of the word
        while(index >= 0 && s[index] != ' ' ) {
            index--;
            res++;
        }
        return res;
    }
};
