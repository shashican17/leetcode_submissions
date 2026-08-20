class Solution {
public:
    bool isValid(string s){
        int bal = 0;
        for(char ch : s){
            if(ch == '('){
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

    void helpGenerateParenthesis(int n, string s, vector<string> &vec){
        if(s.size() == 2*n){
            if(isValid(s)){
                vec.emplace_back(s);
            }
            return;
        }

        helpGenerateParenthesis(n, s + "(", vec);
        helpGenerateParenthesis(n, s + ")", vec);
    }
    vector<string> generateParenthesis(int n) {
        vector<string> vec;
        helpGenerateParenthesis(n, "", vec);
        return vec;
    }
};