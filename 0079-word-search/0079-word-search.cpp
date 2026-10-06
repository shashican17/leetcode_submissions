class Solution {
    bool solve(vector<vector<char>>& board, string word, int i, int j, int k){
        if(k == word.size()){
            return true;
        }
        if(i<0 || j<0 || i>=board.size() || j>=board[0].size()){
            return false;
        }
        if(board[i][j] != word[k]){
            return false;
        }
        char temp = board[i][j];
        board[i][j] = '#';
        bool found = solve(board, word, i-1, j, k+1) ||
                     solve(board, word, i, j-1, k+1) ||
                     solve(board, word, i+1, j, k+1) ||
                     solve(board, word, i, j+1, k+1);
        board[i][j] = temp;
        return found;
    }
public:
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if(solve(board, word, i, j, 0)){
                    return true;
                }
            }
        }
        return false;
    }
};