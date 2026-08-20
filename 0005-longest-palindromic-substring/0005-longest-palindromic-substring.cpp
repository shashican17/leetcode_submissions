class Solution {
    string solve(string s, int l, int r){
        while(l >=0 && r <s.length() && s[l] == s[r]){
            l--;
            r++;
        }
        return s.substr(l+1, r-l-1);
    }
public:
    string longestPalindrome(string s) {
        int n = s.length();
        if(n < 2){
            return s;
        }
        string res = "";

        for(int i=0;i<n-1;i++){
            string s1 = solve(s, i, i);
            string s2 = solve(s, i, i+1);
            if(s1.length() > res.length()){
                res = s1;
            }
            if(s2.length() > res.length()){
                res = s2;
            }
        }
        return res;
    }
};