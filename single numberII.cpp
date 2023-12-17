/* Single Number II

Given an integer array nums where every element appears three times except for one, which appears exactly once. Find the single element and return it.

You must implement a solution with a linear runtime complexity and use only constant extra space.*/

class Solution {
public:
    int singleNumber(vector<int>& nums) {
        vector<long long> v;
        for(auto x:nums) {
            v.push_back(x+(1LL<<31));
        }
        int bit[33]={0};
        for(auto x:v) {
            for(int j=0;j<33;j++) {
                if(x&(1LL<<j)) bit[j]++;
            }
        }
        long long ans=0;
        for(int i=0;i<33;i++) {
            if(bit[i]%3) ans+=(1LL<<i);
        }
        ans-=(1LL<<31);
        return ans;
    }
};