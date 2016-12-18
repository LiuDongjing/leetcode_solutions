//Pascal's Triangle
class Solution {
public:
    vector<vector<int>> generate(int numRows) {
        vector<vector<int>> ret(numRows);
        if (numRows <= 0)
            return ret;
        ret[0] = vector<int> (1, 1);
        if(numRows == 1)
            return ret;
        ret[1] = vector<int> (2, 1);
        if(numRows == 2)
            return ret;
        for (int i = 2;i < numRows;i ++) {
            vector<int> tmp(i + 1);
            tmp[0] = tmp[i] = 1;
            for (int j = 1; j < i;j++)
                tmp[j] = ret[i - 1][j] + ret[i - 1][j - 1];
            ret[i] = tmp;
        }
        return ret;
    }
};
