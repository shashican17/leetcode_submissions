class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        vector<vector<int>> copy = grid;
        int n = grid.size();
        int m = grid[0].size();
        queue<pair<int, int>> q;
        vector<vector<bool>> visited(n, vector<bool>(m, false));
        int fresh = 0;
        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(copy[i][j] == 2){
                    q.push({i, j});
                }else if(copy[i][j] == 1){
                    fresh++;
                }
            }
        }
        int res = 0;
        int delRow[] = {0,1,0,-1};
        int delCol[] = {1,0,-1,0};
        while(!q.empty() && fresh > 0){
            int size = q.size();
            res++;
            for(int i=0;i<size;i++){
                auto [r, c] = q.front();
                q.pop();
                for(int j=0;j<4;j++){
                    int row = r + delRow[j];
                    int col = c + delCol[j];
                    if(row >= 0 && row < n
                        && col >= 0 && col < m
                        && copy[row][col] == 1){
                            copy[row][col] = 2;
                            q.push({row, col});
                            fresh--;
                        }
                }
            }
            
        }
        if(fresh == 0){
            return res;
        }else{
            return -1;
        }
    }
};