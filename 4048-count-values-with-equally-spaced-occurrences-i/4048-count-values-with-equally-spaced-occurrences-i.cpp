class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int res = 0;
        map<int, vector<int>> mp;

        for(int i=0;i<nums.size();i++){
            int val = nums[i];
            mp[val].push_back(i);
        }

        for(auto it : mp){
            if(it.second.size() == 3 && it.second[1] - it.second[0] == it.second[2] - it.second[1]){
                res++;
            }
        }
        return res;
    }
};