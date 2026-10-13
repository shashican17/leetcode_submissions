class Solution {
public:
    int majorityElement(vector<int>& nums) {
        map<int, int> freq;
        for(int i : nums){
            freq[i]++;
            if(freq[i] > nums.size() / 2){
                return i;
            }
        }
        return -1;
    }
};