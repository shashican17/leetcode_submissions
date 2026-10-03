class Solution {
    void solve(vector<int>& nums, int curr, vector<int> vals, vector<vector<int>>& res){
        if(curr == nums.size()){
            res.push_back(vals);
            return;
        }
        vals.push_back(nums[curr]);
        solve(nums, curr+1, vals, res);
        vals.pop_back();
        solve(nums, curr+1, vals, res);
    }
public:
    vector<vector<int>> subsets(vector<int>& nums) {
        vector<vector<int>> res;
        vector<int> vals;
        solve(nums, 0, vals, res);
        return res;
    }
};