class Solution {
public:
    vector<vector<string>> ans;
    int x[20];

    int place(int row, int col) {
        for (int i = 0; i < row; i++) {
            if (x[i] == col || abs(x[i] - col) == abs(i - row))
                return 0;
        }
        return 1;
    }

    void queen(int row, int n) {

        for (int col = 0; col < n; col++) {

            if (place(row, col)) {

                x[row] = col;

                if (row == n - 1) {

                    vector<string> board;

                    for (int i = 0; i < n; i++) {
                        string s(n, '.');
                        s[x[i]] = 'Q';
                        board.push_back(s);
                    }

                    ans.push_back(board);
                }
                else {
                    queen(row + 1, n);
                }
            }
        }
    }

    vector<vector<string>> solveNQueens(int n) {
        queen(0, n);
        return ans;
    }
};