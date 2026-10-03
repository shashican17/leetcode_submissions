class Solution {
    void solve(vector<int>& nums, vector<bool> seen, vector<int> vals, vector<vector<int>>& res){
        if(vals.size() == nums.size()){
            res.push_back(vals);
            return;
        }
        for(int i=0;i<nums.size();i++){
            if(!seen[i]){
                seen[i] = true;
                vals.push_back(nums[i]);
                solve(nums, seen, vals, res);
                vals.pop_back();
                seen[i] = false;
            }
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> res;
        vector<bool>seen(nums.size(), false);
        solve(nums, seen, {}, res);
        return res;
    }
};