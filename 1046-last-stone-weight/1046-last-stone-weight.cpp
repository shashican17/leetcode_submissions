class Solution {
public:
    int lastStoneWeight(vector<int>& stones) {
        priority_queue<int> mH;

        for(int i : stones){
            mH.push(i);
        }

        while(mH.size() > 1){
            int top1 = mH.top();
            mH.pop();
            int top2 = mH.top();
            mH.pop();
            if(top1 != top2){
                mH.push(top1 - top2);
            }else{
                mH.push(0);
            }
        }
        return mH.top();
    }
};