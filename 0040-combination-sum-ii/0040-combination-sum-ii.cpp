class Solution {
    void solve(vector<int>& nums, int sum, int curr, vector<int> vals, vector<vector<int>>& res, int target){
        if(sum == target){
            res.push_back(vals);
            return;
        }
        for(int i=curr; i < nums.size(); i++){
            if( i > curr && nums[i] == nums[i-1]){
                continue;
            }
            if(sum + nums[i] > target){
                break;
            }
            vals.push_back(nums[i]);
            solve(nums, sum + nums[i], i+1, vals, res, target);
            vals.pop_back();
        }
    }
public:
    vector<vector<int>> combinationSum2(vector<int>& candidates, int target) {
        sort(candidates.begin(), candidates.end());
        vector<vector<int>> res;
        solve(candidates, 0, 0, {}, res, target);
        return res;
    }
};