//435.Non-overlapping Intervals
//
/**
 * Definition for an interval.
 * struct Interval {
 *     int start;
 *     int end;
 *     Interval() : start(0), end(0) {}
 *     Interval(int s, int e) : start(s), end(e) {}
 * };
 */
class Solution {
public:
    int eraseOverlapIntervals(vector<Interval>& intervals) {
        vector<set<int>> cross(intervals.size());
        for(int i = 0;i < intervals.size();i++) {
            for(int j = i + 1; j < intervals.size();j++) {
                if(!(intervals[i].end <= intervals[j].start || intervals[j].end <= intervals[i].start)) {
                    cross[i].insert(j);
                    cross[j].insert(i);
                }
            }
        }
        int cnt = 0;
        int index = -1;
        do {
            int maxsz = 0;
            index = -1;
            for(int i = 0;i < cross.size();i++) {
                if(!cross[i].empty()){
                    if(cross[i].size() > maxsz) {
                        maxsz = cross[i].size();
                        index = i;
                    }
                }
            }
            if(index >= 0) {
                cnt++;
                for(auto &e:cross[index]) {
                    cross[e].erase(index);
                }
            }
        }while(index >= 0);
        return cnt;
    }
};