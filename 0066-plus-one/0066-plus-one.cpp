class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        vector<int> res;
        int i = digits.size() - 1;
        if(i < 0){
            return res;
        }
        int carry = 0;
        digits[i] += 1;
        while(i >= 0){
            int val = carry + digits[i];
            digits[i] = val % 10;
            carry = val / 10;
            res.push_back(digits[i]);
            i--;
        }
        if(carry){
            res.push_back(1);
        }
        reverse(res.begin(), res.end());
        return res;
    }
};