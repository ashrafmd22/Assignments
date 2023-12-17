/*Sudoku Solver

Write a program to solve a Sudoku puzzle by filling the empty cells.

A sudoku solution must satisfy all of the following rules:

Each of the digits 1-9 must occur exactly once in each row.
Each of the digits 1-9 must occur exactly once in each column.
Each of the digits 1-9 must occur exactly once in each of the 9 3x3 sub-boxes of the grid.
The '.' character indicates empty cells.*/
class Solution {
public:
    bool issafe(vector<vector<char>>& a,int r, int c,char ca){
        int n=a.size();
        for(int i=0;i<n;i++){
            if(a[i][c]==ca) return false;
            if(a[r][i]==ca) return false;
        }
        int nr=(r/3)*3;
        int nc=(c/3)*3;
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(a[i+nr][j+nc]==ca) return false;
            }
        }
        return true;
    }
    bool solve(vector<vector<char>>& a){
        int n=a.size();
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(a[i][j]=='.'){
                    for(char c='1';c<='9';c++){
                        if(issafe(a,i,j,c)){
                            a[i][j]=c;
                            if(solve(a)) return true;
                            else a[i][j]='.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    void solveSudoku(vector<vector<char>>& a) {
        solve(a);
    }
};