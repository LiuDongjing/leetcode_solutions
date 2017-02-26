//contest21_p3
class Solution {
private:
    bool match(string &s, string &t){
        if(s.size() < t.size()) return false;
        int i = 0, j = 0;
        while(i < s.size() && j < t.size() && (s.size() - i >= t.size() - j)) {
            for(;i < s.size() && s[i] != t[j];i++);
            if(i < s.size()) {
                i++;
                j++;
            }
        }
        if(j >= t.size()) return true;
        return false;
    }
public:
   static bool cmp(string &a, string &b) {
        if(a.size() > b.size()) return true;
        if(a.size() < b.size()) return false;
        return a < b;
    }
public:
    string findLongestWord(string s, vector<string>& d) {
        vector<string> con;
        for(int i = 0; i < d.size(); i++) {
            if(match(s, d[i])) con.push_back(d[i]);
        }
        if(con.size() == 0) return "";
        sort(con.begin(), con.end(), cmp);
        return con[0];
    }
};