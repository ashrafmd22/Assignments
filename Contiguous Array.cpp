/*Contiguous Array

Given a binary array nums, return the maximum length of a contiguous subarray with an equal number of 0 and 1.

 */
 class Solution {
public:
    int findMaxLength(vector<int>& nums) {
		int maxlen = 0;
        for (int i = 0; i < nums.size(); i++) {
            int zeroes = 0, ones = 0;
            for (int j = i; j < nums.size(); j++) {
                if (nums[j] == 0) {
                    zeroes++;
                } else {
                    ones++;
                }
                if (zeroes == ones) {
                    maxlen = max(maxlen, j - i + 1);
                }
            }
        }
        return maxlen;
    }
};