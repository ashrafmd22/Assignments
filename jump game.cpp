/*Jump Game

You are given an integer array nums. You are initially positioned at the array's first index, and each element in the array represents your maximum jump length at that position.

Return true if you can reach the last index, or false otherwise.*/

class Solution {
public:
    bool canJump(vector<int>& a) {
        int n=a.size();
        int goodPos=a.size()-1;
        int i=n-2;
        while(i>=0){
            if(a[i]+i >= goodPos) goodPos=i;
            i--;
        }
        if(goodPos == 0) return true;
        return false;
    }
};