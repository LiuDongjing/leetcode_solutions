//Find All Anagrams in a String
class Solution {
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
