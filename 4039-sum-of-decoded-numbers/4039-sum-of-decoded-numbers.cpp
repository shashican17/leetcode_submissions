class Solution {
public:
    long long MOD = 1000000007LL;
    long long modPow(long long a, long long b) {
        long long res = 1;
        a %= MOD;

        while (b > 0) {
            if (b & 1)
                res = (res * a) % MOD;

            a = (a * a) % MOD;
            b >>= 1;
        }

        return res;
    }
    
    int sumDecoded(vector<long long>& nums) {
        int n = nums.size();
        long long res = 0;
        for(int i=0;i<n;i++){
            long long val = nums[i];
            int w = val % 10;
            int di = val / 10;
            string s = to_string(val);
            s = s.substr(0, s.size()-1);
            long long xi = stoll(s.substr(0, w));
            long long yi = stoll(s.substr(w));

            long long curr = modPow(xi, yi);
            res += curr % MOD;
        }
        return (int)(res % MOD);
    }
};