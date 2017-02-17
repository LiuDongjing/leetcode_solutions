//Find All Anagrams in a String
//这个方法会超时
/*class Solution {
public:
    vector<int> findAnagrams(string s, string p) {
        vector<int> index;
        int len = p.size();
        sort(p.begin(), p.end());
        int upb = s.size() - len;
        for(int i = 0; i <= upb; i++) {
            string sub = s.substr(i, len);
            sort(sub.begin(), sub.end());
            if(sub == p)
                index.push_back(i);
        }
        return index;
    }
};
*/
// 这个方法可以，基本思路是把p变成26个字母的直方图，每次比较也是
// 直方图比较，移动index的时候修改s的直方图
class Solution {
private:
    bool isEqual(int v1[], int v2[]) {
        for(int i = 0;i < 26;i++)
            if(v1[i] != v2[i]) return false;
        return true;
    }
public:
    vector<int> findAnagrams(string s, string p) {
        int pvec[26], svec[26];
        for(int i = 0;i < 26; i++) {
            pvec[i] = 0;
            svec[i] = 0;
        }
        for(int i = 0;i < p.size();i++) {
            pvec[p[i] - 'a']++;
        }
        vector<int> ret;
        if(s.size() < p.size())
            return ret;
        for(int i = 0; i < p.size();i++) svec[s[i] - 'a']++;
        for(int i = 0;i <= s.size() - p.size(); i++) {
            if(isEqual(pvec, svec)) ret.push_back(i);
            svec[s[i] - 'a']--;
            if(i + p.size() < s.size())
                svec[s[i+p.size()] - 'a']++;
        }
        return ret;
    }
};