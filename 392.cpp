//392. Is Subsequence
class Solution {
public:
    bool isSubsequence(string s, string t) {
        int k = t.size() - 1;
        for(int i = s.size() - 1; i >= 0; i--) {
            for(;k >= 0 && t[k] != s[i];k--);
            if(k >= 0) k--;
            else return false;
        }
        return true;
    }
};