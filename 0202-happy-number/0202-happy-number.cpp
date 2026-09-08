class Solution {
    int squareSum(int n){
        int sum = 0;
        while(n > 0){
            int val = n%10;
            sum += val*val;
            n /= 10;
        }
        return sum;
    }
public:
    bool isHappy(int n) {
        set<int> st;
        while(st.find(n) == st.end()){
            st.insert(n);
            n = squareSum(n);
            if(n == 1){
                return true;
            }
        }
        return false;
    }
};