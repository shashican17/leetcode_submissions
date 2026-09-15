class Solution {
public:
    int strStr(string haystack, string needle) {
        int l1 = haystack.size();
        int l2 = needle.size();
        if(l2 > l1){
            return -1;
        }

        for(int i=0;i<=l1-l2;i++){
            if(haystack.substr(i, l2) == needle){
                return i;
            }
        }

        return -1;
    }
};