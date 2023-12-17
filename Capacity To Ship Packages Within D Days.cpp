/*Capacity To Ship Packages Within D Days

A conveyor belt has packages that must be shipped from one port to another within days days.

The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.

Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.*/

class Solution {
public:
    bool isvalid(int mid,vector<int>&weights,int days){
        int sum=0;
        int ans=1;
        for(auto x: weights){
            sum+=x;
            if(x>mid){
                return false;
            }
            if(sum>mid){
                ans++;
                sum=x;
            }
        }
        if(ans<=days){
            return true;
        }
        return false;
    }
    int shipWithinDays(vector<int>& weights, int days) {
        int lo=1;
        int hi=0;
        for(auto x: weights){
            hi+=x;
        }
        int ans=hi;
        
        while(hi>=lo){
            int mid=lo+(hi-lo)/2;
            if(isvalid(mid,weights,days)){
                ans=mid;
                hi=mid-1;
            }
            else{
                lo=mid+1;
            }
        }
        return ans;
    }
};