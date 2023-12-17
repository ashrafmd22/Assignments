/*Trapping Rain Water

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.*/
class Solution {
public:
    //total water is trapped into the bars
    int trap(vector<int>& h) {
        int l=0,r=h.size()-1,lmax=INT_MIN,rmax=INT_MIN,ans=0;
        while(l<r){
            lmax=max(lmax,h[l]);
            rmax=max(rmax,h[r]);
            ans+=(lmax<rmax)?lmax-h[l++]:rmax-h[r--];
        }
        return ans;
    }
};