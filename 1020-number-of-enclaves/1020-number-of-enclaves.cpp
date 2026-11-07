class Solution {
public:
    int numEnclaves(vector<vector<int>>& grid) {
        vector<vector<int>> copy = grid;
        int res = 0;
        int n = copy.size();
        int m = copy[0].size();

        queue<pair<int, int>> q;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                res += copy[i][j];
                if((i==0 || j==0 || i==n-1 || j==m-1) && copy[i][j]==1){
                    copy[i][j] = 0;
                    q.push({i, j});
                    res--;
                }
            }
        }

        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;

            q.pop();

            int delRow[] = {0,1,0,-1};
            int delCol[] = {1,0,-1,0};

            for(int i=0;i<4;i++){
                int nrow = r + delRow[i];
                int ncol = c + delCol[i];

                if(nrow >= 0 && nrow < n
                && ncol >= 0 && ncol < m
                && copy[nrow][ncol]){
                    copy[nrow][ncol] = 0;
                    q.push({nrow, ncol});
                    res--;
                }
            }
        }
        return res;
    }
};