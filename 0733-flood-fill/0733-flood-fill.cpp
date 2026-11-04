class Solution {
    void dfs(int r, int c, vector<vector<int>>& res, vector<vector<int>>& image, int n, int m, int delRow[], int delCol[], int color, int val){
        res[r][c] = color;
        for(int i=0;i<4;i++){
            int newRow = r + delRow[i];
            int newCol = c + delCol[i];
            if(newRow >= 0 && newRow < n
                && newCol >= 0 && newCol < m
                && image[newRow][newCol] == val
                && res[newRow][newCol] != color){
                    dfs(newRow, newCol, res, image, n, m, delRow, delCol, color, val);
                }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int val = image[sr][sc];
        vector<vector<int>> res = image;
        int n = image.size();
        int m = image[0].size();
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        dfs(sr, sc, res, image, n, m, delRow, delCol, color, val);
        return res;
    }
};