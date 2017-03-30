//406. Queue Reconstruction by Height
class Solution {
public:
    static bool cmp(pair<int, int> &a, pair<int, int> &b) {
        if(a.first < b.first) return true;
        else if(a.first > b.first) return false;
        else return a.second > b.second;
    }
public:
    vector<pair<int, int>> reconstructQueue(vector<pair<int, int>>& people) {
        sort(people.begin(), people.end(), cmp);
        vector<int> index(people.size(), -1);
        for(int i = 0; i < people.size(); i++) {
            int cnt = 0;
            for(int j = 0; j < people.size(); j++) {
                if(cnt == people[i].second && index[j] < 0) {
                    index[j] = i;
                    break;
                }
                if(index[j] < 0) cnt++;
            }
        }
        vector<pair<int, int>> ret(people.size());
        for(int i = 0;i < ret.size(); i++) {
            ret[i] = people[index[i]];
        }
        return ret;
    }
};