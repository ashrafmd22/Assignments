/* N-Queens

The n-queens puzzle is the problem of placing n queens on an n x n chessboard such that no two queens attack each other.

Given an integer n, return all distinct solutions to the n-queens puzzle. You may return the answer in any order.

Each solution contains a distinct board configuration of the n-queens' placement, where 'Q' and '.' both indicate a queen and an empty space, respectively.*/

class Solution {
public:
    bool isvalid(vector<string>& board,int i,int c,int n){
        //uska col
        for(int r=0;r<i;r++){
            if(board[r][c]=='Q') return false;
        }
        int tr=i;
        int tc=c;
        while(tr>=0 and tc>=0){
            if(board[tr][tc]=='Q') return false;
            tr--;
            tc--;

        }
        tr=i;
        tc=c;
        while(tr>=0 and tc<n){
            if(board[tr][tc]=='Q') return false;
            tr--;
            tc++;

        }
        return true;
        

    }
    void help(vector<vector<string>>& ans,vector<string>& board,int i,int n){
      if(i==n){
          ans.push_back(board);
           return;}
      for(int c=0;c<n;c++){
          if(isvalid(board,i,c,n)){
              board[i][c]='Q';
              help(ans,board,i+1,n);
              board[i][c]='.';
          }
      }
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n,string(n,'.'));
        help(ans,board,0,n);
        return ans;

    }
};