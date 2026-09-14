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
            vector<int> & vec = it.second;
            if(vec.size() == 3 && vec[1] - vec[0] == vec[2] - vec[1]){
                res++;
            }
        }
        return res;
    }
};