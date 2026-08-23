class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        // map<string, vector<string>> mp;
        // int n = strs.size();
        // for(int i=0;i<n;i++){
        //     string temp = strs[i];
        //     sort(temp.begin(), temp.end());
        //     mp[temp].push_back(strs[i]);
        // }

        // vector<vector<string>> res;
        // for(auto &val : mp){
        //     res.push_back(val.second);
        // }
        // return res;


        map<string, vector<string>> mp;
        int n = strs.size();
        for(int i=0;i<n;i++){
            vector<int> count(26,0);
            for(char ch : strs[i]){
                count[ch - 'a']++;
            }
            string val = to_string(count[0]);
            for(int j=1;j<26;j++){
                val += ',' + to_string(count[j]);
            }
            mp[val].push_back(strs[i]);
        }

        vector<vector<string>> res;
        for(auto &val : mp){
            res.push_back(val.second);
        }
        return res;
    }
};