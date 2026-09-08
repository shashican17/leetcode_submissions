class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        vector<int> res;
        if(m == 0){
            return res;
        }
        int n = matrix[0].size();
        int sr = 0, sc = 0;
        int er = m-1, ec = n-1;
        while(sr<=er && sc<=ec){
            for(int j=sc;j<=ec;j++){
                res.push_back(matrix[sr][j]);
            }
            sr++;
            for(int i=sr;i<=er;i++){
                res.push_back(matrix[i][ec]);
            }
            ec--;
            if(sr<=er){
                for(int j=ec;j>=sc;j--){
                    res.push_back(matrix[er][j]);
                }
            }
            er--;
            if(sc<=ec){
                for(int i=er;i>=sr;i--){
                    res.push_back(matrix[i][sc]);
                }
            }
            sc++;
        }
        return res;
    }
};