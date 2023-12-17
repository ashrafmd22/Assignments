// Sliding Window Maximum

// You are given an array of integers nums, there is a sliding window of size k which is moving from the very left of the array to the very right. You can only see the k numbers in the window. Each time the sliding window moves right by one position.

// Return the max sliding window.
class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& a, int k) {
        deque<int> dq;
        vector<int> ans;
        for(int i=0;i<k;i++){
            while(!dq.empty() and dq.back()<a[i]) dq.pop_back();
            dq.push_back(a[i]);
        }
        ans.push_back(dq.front());
        for(int i=k;i<a.size();i++){
            if(dq.front()==a[i-k]) dq.pop_front();
             while(!dq.empty() and dq.back()<a[i]) dq.pop_back();
            dq.push_back(a[i]);
        ans.push_back(dq.front());
            
        }
        return ans;
    }
};