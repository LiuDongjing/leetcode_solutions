//Power of Four
class Solution {
public:
    bool isPowerOfFour(int num) {
        return dat.find(num) != dat.end();
    }
    Solution() {
        dat.insert(1);
        int m = 1;
        for (int i = 1;i <= 15;i++) {
            m *= 4;
            dat.insert(m);
        }
    }
private :
    set<int> dat;
};
