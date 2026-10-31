class Solution {
    void dfs(vector<vector<int>>& adj, int node, vector<bool>& visited){
        visited[node] = true;
        for(auto it : adj[node]){
            if(!visited[it]){
                dfs(adj, it, visited);
            }
        }
    }
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<vector<int>> adj(n);
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(isConnected[i][j] == 1 && i != j){
                    adj[i].push_back(j);
                    adj[j].push_back(i);
                }
            }
        }
        vector<bool> visited(n, false);
        int res = 0;
        for(int i=0;i<n;i++){
            if(!visited[i]){
                res++;
                dfs(adj, i, visited);
            }
        }
        return res;
    }
};