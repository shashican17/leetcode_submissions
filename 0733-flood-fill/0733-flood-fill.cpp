class Solution {
    void dfs(int r, int c, vector<vector<int>>& res, vector<vector<int>>& image, int newColor, int delRow[], int delCol[], int iniColor, int n, int m){
        res[r][c] = newColor;
        for(int i=0;i<4;i++){
            int nrow = r + delRow[i];
            int ncol = c + delCol[i];
            if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m
            && image[nrow][ncol] == iniColor 
            && res[nrow][ncol] != newColor){
                dfs(nrow, ncol, res, image, newColor, delRow, delCol, iniColor, n, m);
            }
        }
    }
public:
    vector<vector<int>> floodFill(vector<vector<int>>& image, int sr, int sc, int color) {
        int iniColor = image[sr][sc];
        vector<vector<int>> res = image;
        int delRow[] = {-1, 0, 1, 0};
        int delCol[] = {0, 1, 0, -1};
        int n = image.size();
        int m = image[0].size();
        dfs(sr, sc, res, image, color, delRow, delCol, iniColor, n, m);
        return res;
    }
};