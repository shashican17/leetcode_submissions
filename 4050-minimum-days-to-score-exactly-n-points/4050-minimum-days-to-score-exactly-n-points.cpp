class Solution {
public:
    int minDays(int n) {
        vector<int> dp(n+1, INT_MAX);
        dp[0] = 0;
        int v = 1, k = 1;
        while(v <= n){
            dp[v] = k;
            for(int i=v+1;i<=min(n, v+v);i++){
                dp[i] = min(dp[i], dp[i-v] + k + 1);
            }
            k++;
            v += k;
        }
        return dp[n];
    }
};