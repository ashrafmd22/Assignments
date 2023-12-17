/*Valid Sudoku

Determine if a 9 x 9 Sudoku board is valid. Only the filled cells need to be validated according to the following rules:

Each row must contain the digits 1-9 without repetition.
Each column must contain the digits 1-9 without repetition.
Each of the nine 3 x 3 sub-boxes of the grid must contain the digits 1-9 without repetition.
Note:

A Sudoku board (partially filled) could be valid but is not necessarily solvable.
Only the filled cells need to be validated according to the mentioned rules.*/

class Solution {
public:
    bool isValidSudoku(vector<vector<char>>& board)
    {
        bool m[9][9] = {0}, m2[9][9] = {0}, m3[9][9] = {0};

        for (int i = 0; i < 9; i++)
            for (int j = 0; j < 9; j++)
                if (board[i][j] != '.') {
                    int num = board[i][j] - '0' - 1;
                    int k = i / 3 * 3 + j / 3;

                    if (m[i][num] || m2[j][num] || m3[k][num])
                        return false;

                    m[i][num] = m2[j][num] = m3[k][num] = 1;
                }

        return true;
    }
};