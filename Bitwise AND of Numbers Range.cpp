/*Bitwise AND of Numbers Range

Given two integers left and right that represent the range [left, right], return the bitwise AND of all numbers in this range, inclusive.*/

class Solution {
public:
    int rangeBitwiseAnd(int l, int r) {
       int c=0;
       while(l!=r)
       {
           l>>=1;
           r>>=1;
           c++;
       }
       return l<<c;
    }
};