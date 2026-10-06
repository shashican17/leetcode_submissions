class Solution {
    void backtrack(string digits, vector<string>& mp, string val, vector<string>& res, int i){
        if(val.size() == digits.size()){
            res.push_back(val);
            return;
        }
        string curr = mp[digits[i] - '0'];
        for(char ch : curr){
            backtrack(digits, mp, val+ch, res, i+1);
        }
    }
public:
    vector<string> letterCombinations(string digits) {
        vector<string> mp = {"", "", "abc", "def", "ghi", "jkl", "mno",
                             "pqrs", "tuv", "wxyz"};
        vector<string> res;
        backtrack(digits, mp, "", res, 0);
        return res;
    }
};