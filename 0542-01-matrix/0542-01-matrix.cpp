class Solution {
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        int n = mat.size();
        int m = mat[0].size();
        vector<vector<int>> res(n, vector<int>(m));
        vector<vector<bool>> visited(n, vector<bool>(m, false));

        queue<pair<pair<int, int>, int>> q;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(mat[i][j] == 0){
                    visited[i][j] = true;
                    res[i][j] = 0;
                    q.push({{i, j}, 0});
                }
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int dist = q.front().second;
            q.pop();

            int delRow[] = {0, 1, 0, -1};
            int delCol[] = {1, 0, -1, 0};

            for(int i=0;i<4;i++){
                int nrow = row + delRow[i];
                int ncol = col + delCol[i];
                if(nrow >= 0 && nrow < n
                    && ncol >= 0 && ncol < m
                    && !visited[nrow][ncol]){
                        visited[nrow][ncol] = true;
                        int currDist = dist + abs(nrow - row) + abs(ncol - col);
                        q.push({{nrow, ncol}, currDist});
                        res[nrow][ncol] = currDist;
                    }
            }
        }
        return res;
    }
};