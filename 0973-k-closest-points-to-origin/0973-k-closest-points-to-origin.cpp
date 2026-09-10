class Solution {
public:
    vector<vector<int>> kClosest(vector<vector<int>>& points, int k) {
        map<double, vector<vector<int>>> mp;
        priority_queue<double, vector<double>, greater<double>> mH;

        for(auto val : points){
            int x = val[0];
            int y = val[1];
            double dist = sqrt(x*x + y*y);
            mp[dist].push_back(val);
            mH.push(dist);
        }

        vector<vector<int>> res;
        while(!mH.empty()){
            double dist = mH.top();
            mH.pop();
            for(auto val : mp[dist]){
                if(res.size() == k){
                    return res;
                }
                res.push_back(val);
            }
        }
        return res;
    }
};