class Solution {
    bool isValid(string s){
        int bal = 0;
        for(int i=0;i<s.size();i++){
            if(s[i] == '('){
                bal++;
            }else{
                bal--;
            }
            if(bal < 0){
                return false;
            }
        }
        return bal == 0;
    }

    void helpGenerateParenthesis(int n, string s, vector<string>& res){
        if(s.size() == 2 * n){
            if(isValid(s)){
                res.push_back(s);
            }
            return;
        }
        helpGenerateParenthesis(n, s+'(', res);
        helpGenerateParenthesis(n, s+')', res);
    }
public:
    vector<string> generateParenthesis(int n) {
        vector<string> res;
        helpGenerateParenthesis(n, "", res);
        return res;
    }
};