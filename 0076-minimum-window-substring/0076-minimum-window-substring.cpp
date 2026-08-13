class Solution {
public:
    string minWindow(string s, string t) {
        int m = s.size();
        int n = t.size();
        if(m < n){
            return "";
        }
        map<char, int> mp2, mp1;

        for(char ch : t){
            mp2[ch]++;
        }

        int i = 0;
        int j = 0;
        int need = mp2.size();
        int have = 0;
        int minSize = INT_MAX;
        pair<int, int> req;

        while (j < m){
            char c = s[j];
            mp1[c]++;
            
            if(mp2.count(c) && mp1[c] == mp2[c]){
                have++;
            }
            while(have == need){
                int len = j - i + 1;
                if (len < minSize){
                    minSize = len;
                    req = {i, j};
                }
                mp1[s[i]]--;
                if(mp2.count(s[i]) && mp2[s[i]] > mp1[s[i]]){
                    have--;
                }
                i++;
            }
            j++;
        }
        return minSize == INT_MAX ? "" : s.substr(req.first, minSize);        
    }
};