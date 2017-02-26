//contest21_p4
//Minesweeper
//题目并不难，就是编码有些麻烦
class Solution {
public:
    vector<vector<char>> updateBoard(vector<vector<char>>& board, vector<int>& click) {
        int row = board.size();
        int col = board[0].size();
        int rs[8] = {-1, -1, 0, 1, 1, 1, 0, -1};
        int cs[8] = {0, 1, 1, 1, 0, -1, -1, -1};
        vector<vector<bool>> flag(row, vector<bool>(col, true));
        if(board[click[0]][click[1]] == 'M') {
                board[click[0]][click[1]] = 'X';
                return board;
        }
        queue<pair<int, int>> que;
        que.push(pair<int, int>(click[0], click[1]));
        while(!que.empty()) {
            auto h = que.front();
            flag[h.first][h.second] = false;
            if(board[h.first][h.second] == 'E') {
                int bob = 0;
                for(int i = 0; i < 8;i++) {
                    int r = h.first + rs[i];
                    int c = h.second + cs[i];
                    if(r >= 0 && r < row && c >= 0 && c < col) {
                        if(board[r][c] == 'M') bob++;
                    }
                }
                if(bob > 0) board[h.first][h.second] = '0' + bob;
                else{
                    board[h.first][h.second] = 'B';
                    for(int i = 0; i < 8;i++) {
                        int r = h.first + rs[i];
                        int c = h.second + cs[i];
                        if(r >= 0 && r < row && c >= 0 && c < col) {
                            if(flag[r][c] == true) que.push(pair<int,int>(r, c));
                        }
                    }
                }
            }
            que.pop();
        }
    return board;
    }
};