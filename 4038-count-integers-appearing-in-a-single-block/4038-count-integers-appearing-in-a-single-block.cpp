class Solution {
public:
    int countSpecialIntegers(vector<int>& nums) {
        map<int, int> mp;
        set<int> st(nums.begin(), nums.end());

        for(int i=0;i<nums.size();i++){
            if(mp.count(nums[i])){
                if(mp[nums[i]] != i-1){
                    st.erase(nums[i]);
                }
            }
            mp[nums[i]] = i;
        }

        return st.size();
    }
};