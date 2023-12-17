/*Kth Smallest Number in Multiplication Table

Nearly everyone has used the Multiplication Table. The multiplication table of size m x n is an integer matrix mat where mat[i][j] == i * j (1-indexed).

Given three integers m, n, and k, return the kth smallest element in the m x n multiplication table.*/

class Solution {
public:
    int findKthNumber(int m, int n, int k) {
        int l=1, L=m*n;
        while (L) {
            int d=L>>1;
            int x=l+d;
            int y=0;
            for (int a=n, b=0; a>0; --a) {
                while (b<=m and a*b<=x) ++b;
                y+=b-1;
            }
            if (y<k) {
                l=x+1;
                L-=d+1;
            } else
                L=d;
        }
        return l;
    }
};