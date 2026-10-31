class Solution {
    void bfs(int r, int c, vector<vector<bool>>& visited, vector<vector<char>>& grid, int n, int m){
        visited[r][c] = true;
        queue<pair<int, int>> q;
        q.push({r, c});
        while(!q.empty()){
            int row = q.front().first;
            int col = q.front().second;
            q.pop();
            int delrow[] = {-1,1,0,0};
            int delcol[] = {0,0,-1,1};
            for(int i=0;i<4;i++){
                // for(int delcol=-1;delcol<=1;delcol++){
                    int nrow=row+delrow[i];
                    int ncol=col+delcol[i];
                    if(nrow>=0 && nrow<n 
                        && ncol>=0 && ncol<m 
                        && grid[nrow][ncol]=='1' 
                        && !visited[nrow][ncol]){
                        q.push({nrow, ncol});
                        visited[nrow][ncol] = true;
                    }
                // }
            }
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<bool>>visited(n, vector<bool>(m, false));
        int res = 0;
        for (int row=0;row<n;row++){
            for(int col=0;col<m;col++){
                if(!visited[row][col] && grid[row][col] == '1'){
                    res++;
                    bfs(row, col, visited, grid, n, m);
                }
            }
        }
        return res;
    }
};