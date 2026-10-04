class Solution {
    void solve(vector<int>& nums, vector<vector<int>>& res, vector<int> vals, int curr){
        res.push_back(vals);
        for(int i=curr;i<nums.size();i++){
            if(i > curr && nums[i] == nums[i-1]){
                continue;
            }
            vals.push_back(nums[i]);
            solve(nums, res, vals, i+1);
            vals.pop_back();
        }
    }
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        vector<vector<int>> res;
        solve(nums, res, {}, 0);
        return res;
    }
};