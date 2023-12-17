class Solution {
public:
    bool canPartitionKSubsets(vector<int>& nums, int k) {
        int N = nums.size();
        int sm = accumulate(nums.begin(), nums.end(), 0);
        sort(nums.rbegin(), nums.rend());
        int basket = sm / k;
        int rem = sm % k;
        if(rem || nums[0] > basket) return false;
        vector<int> dp(1 << N, -1);
        dp[0] = 0;
        
        for(int i = 1; i < 1<<N; ++i) {
            for(int j = 0; j < N; ++j) {
                int nei = dp[i ^ (1 << j)];
                if(nei >= 0 && nei + nums[j] <= basket && i & (1 << j)) {
                    dp[i] = (nei + nums[j]) % basket;
                    break;
                }
            }
        }
        return dp.back() == 0;
    }
};