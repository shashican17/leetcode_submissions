class Solution {
    void bfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid, int n, int m){
        visited[r][c] = true;
        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty()){
            int delRow[] = {-1, 0, 1, 0};
            int delCol[] = {0, 1, 0, -1};
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            for(int i=0;i<4;i++){
                int currRow = row + delRow[i];
                int currCol = col + delCol[i];
                if(currRow >= 0 && currRow < n 
                    && currCol >= 0 && currCol < m
                    && !visited[currRow][currCol]
                    && grid[currRow][currCol] == '1'){
                        q.push({currRow, currCol});
                        visited[currRow][currCol] = true;
                    }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        if (n == 0){
            return n;
        }
        int m = grid[0].size();
        int res = 0;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(!visited[i][j] && grid[i][j] == '1'){
                    res++;
                    bfs(i, j, visited, grid, n, m);
                }
            }
        }
        return res;
    }
};