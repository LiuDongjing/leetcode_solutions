//Valid Sudoku
//转换一下思路就行了，按数字来检测而不是位置，记录下9个数字的位置信息，然后再判断是否满足条件。
class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board) {
        vector<pair<int,int>> cnt[9];
        for(int i = 0;i < board.size();i++) {
            for(int j =0; j < board[i].size();j++) {
                if(board[i][j] != '.')
                    cnt[board[i][j] - '0' -1].push_back(pair<int,int>(i,j));
            }
        }
        set<int> x, y;
        for(int i = 0;i < 9;i++) {
            x.clear();
            y.clear();
            for(auto &e : cnt[i]) {
                if(x.find(e.first) != x.end() || y.find(e.second) != y.end()) 
                    return false;
                x.insert(e.first);
                y.insert(e.second);
            }
        }
        for(int i = 0;i < 9;i++) {
            for(int j = 0; j < cnt[i].size();j++) {
                for(int z = j + 1;z < cnt[i].size();z++){
                    int x1 = cnt[i][j].first, x2 = cnt[i][z].first, y1 = cnt[i][j].second, y2 = cnt[i][z].second;
                    if(x1 / 3 == x2 / 3 && y1 / 3 == y2 / 3)
                        return false;
                }
            }
        }
        return true;
    }
};
