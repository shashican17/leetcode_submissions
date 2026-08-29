class Solution {
public:
    vector<int> lexicographicallySmallestArray(vector<int>& nums, int limit) {
        int n = nums.size();
        vector<int> sorted = nums;
        sort(sorted.begin(), sorted.end());

        map<int, vector<int>> groups;
        map<int, int> groupId;
        map<int, int> pos;

        int id = 1;
        groups[id].push_back(sorted[0]);
        groupId[sorted[0]] = id;

        for(int i= 1; i<n;i++){
            if(sorted[i] - sorted[i-1] > limit){
                id++;
            }

            groups[id].push_back(sorted[i]);
            groupId[sorted[i]] = id;
        }

        for(int i=0;i<n;i++){
            int grp = groupId[nums[i]];
            nums[i] = groups[grp][pos[grp]];
            pos[grp]++;
        }
        return nums;
    }
};