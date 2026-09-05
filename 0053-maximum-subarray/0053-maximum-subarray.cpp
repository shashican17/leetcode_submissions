class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        int res = INT_MIN;
        int n = nums.size();
        int i=0;
        int curr = 0;
        while(i < n){
            curr += nums[i];
            res = max(res, curr);
            if(curr < 0){
                curr = 0;
            }
            i++;
        }
        return res;
    }
};