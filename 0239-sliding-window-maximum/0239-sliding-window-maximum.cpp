class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> res;
        priority_queue<pair<int, int>> heap;

        for(int i=0;i<n;i++){
            heap.push({nums[i], i});
            if(i >= k-1){
                while(heap.top().second <= i-k){
                    heap.pop();
                }
                res.push_back(heap.top().first);
            }
        }
        return res;
    }
};