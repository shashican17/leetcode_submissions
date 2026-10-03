class Solution {
    void solve(vector<int>& nums, int sum, int curr, vector<int>vals, vector<vector<int>>& res, int target){
        if(sum == target){
            res.push_back(vals);
            return;
        }
        if(sum > target || curr == nums.size()){
            return;
        }
        vals.push_back(nums[curr]);
        solve(nums, sum + nums[curr], curr, vals, res, target);
        // solve(nums, sum + nums, curr, vals, res);
        vals.pop_back();
        solve(nums, sum, curr+1, vals, res, target);
    }
public:
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        vector<vector<int>> res;
        vector<int> vals;
        solve(candidates, 0, 0, vals, res, target);
        return res;
    }
};