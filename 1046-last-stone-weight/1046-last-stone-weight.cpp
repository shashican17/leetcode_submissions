class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> maxHeap;
        for(int i : stones){
            maxHeap.push(i);
        }
        while(maxHeap.size() >= 2){
            int t1 = maxHeap.top();
            maxHeap.pop();
            int t2 = maxHeap.top();
            maxHeap.pop();
            if(t1 == t2){
                maxHeap.push(0);
            }else{
                maxHeap.push(t1 - t2);
            }
        }
        return maxHeap.top();
    }
};