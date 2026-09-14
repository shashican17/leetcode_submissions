class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        int res = 0;
        map<int, vector<int>> mp;
        for(int i=0;i<nums.size();i++){
            mp[nums[i]].push_back(i);
        }

        for(auto it : mp){
            vector<int> vec = it.second;
            int n = vec.size();
            if(n < 3){
                continue;
            }
            int dist = vec[1] - vec[0];
            bool flag = true;
            for(int i=1;i<n;i++){
                if(dist != vec[i] - vec[i-1]){
                    flag = false;
                    break;
                }
            }
            if(flag){
                res++;
            }
        }
        return res;
    }
};