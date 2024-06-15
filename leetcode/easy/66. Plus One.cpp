class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry = 1;
        int i = digits.size() - 1;
        while(i >= 0 && carry) {
            carry = (digits[i] + 1) / 10;
            digits[i] = (digits[i] + 1) % 10;
            i--;
        }
        if(carry) {
            digits.insert(digits.begin(), 1);
        }
        return digits;
    }
};
