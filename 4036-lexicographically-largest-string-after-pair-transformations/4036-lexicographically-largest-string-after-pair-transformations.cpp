class Solution {
public:
    vector<string> largestString(vector<int>& nums) {
        vector<string> res;

        for(int i : nums){
            string s;
            for (int k = 25; k >= 0; --k){
                int count = i / (1 << k);

                while(count--){
                    s += char('a' + k);
                }

                i %= (1 << k);
            }
            res.push_back(s);
        }
        return res;
    }
};