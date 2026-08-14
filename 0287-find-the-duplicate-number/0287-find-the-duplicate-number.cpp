class Solution {
public:
    int findDuplicate(vector<int>& nums) {
        int n = nums.size();
        set<int> st;
        for(int i=0; i<n; i++){
            int val = nums[i];
            if(st.find(val) == st.end()){
                st.insert(val);
            }else{
                return val;
            }
        }
        return -1;
    }
};