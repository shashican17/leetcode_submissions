class Solution {
    bool dfs(int start, int currCol, vector<vector<int>>& graph, vector<int>& color){
        color[start] = currCol;
        for(auto it : graph[start]){
            if(color[it] == -1){
                if(!dfs(it, !currCol, graph, color)){
                    return false;
                }
            }else if(color[it] == currCol){
                return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> color(n, -1);
        for(int i=0;i<n;i++){
            if(color[i] == -1 && !dfs(i, 0, graph, color)){
                return false;
            }
        }
        return true;
    }
};