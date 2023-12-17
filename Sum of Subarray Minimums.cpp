/*Sum of Subarray Minimums

Given an array of integers arr, find the sum of min(b), where b ranges over every (contiguous) subarray of arr. Since the answer may be large, return the answer modulo 109 + 7.*/

class Solution {
public:
    
    int mod = 1e9+7;
    int sumSubarrayMins(vector<int>& nums) {
        
        
        
        // step 1 find next smaller or equal element index for all number
        // step 2 find prev smaller element index for all numbers

        // step 3 iterate though each i and get the count and add it
        
        int n = nums.size();
        
        vector<int> nse(n); // for this we go till we find equal or lower element 
        vector<int> pse(n); // for this we go till we found the lower one 
        
        // this ensures counting would be done only a single time when both the same elements are included
        
        
        stack<pair<int,int>> st;   // value then index
        st.push({INT_MIN , n}); 
        
        for(int i=n-1;i>=0;i--){
            
            while(st.top().first > nums[i]){
                st.pop();
            }
            
            if(!st.empty()){
                nse[i] = st.top().second;
                if(st.top().first == nums[i])
                    st.pop();
            }
            
            st.push({nums[i],i});
        }
        
        
        stack<pair<int,int>> buffer;
        st = buffer;
        
        st.push({INT_MIN,-1});
        
        for(int i=0;i<n;i++){
            while(st.top().first >= nums[i]){
                st.pop();
            }
            
            if(!st.empty()){
                pse[i] = st.top().second;
            }
            
            st.push({nums[i],i});
        }
        
        
        long long total = 0;
        for(int i=0;i<n;i++){
            
            int p = pse[i]; 
            int n = nse[i];
            // cout<<p<<" "<<i<<" "<<n<<endl;
            
            long long count = (abs(i-p)*1LL*abs(n-i))%mod;
            // total count of the subarrays containing index i as its minimum
            
            long long to_add = (count*1LL*nums[i])%mod;
            // sum of minimums of all that subarrays
            
            // cout<<count<<" "<<to_add<<endl;
            
            total = (total + to_add)%mod;
            
            
        }
        
        return total;
    }
};