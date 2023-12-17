/* Decode XORed Permutation

There is an integer array perm that is a permutation of the first n positive integers, where n is always odd.

It was encoded into another integer array encoded of length n - 1, such that encoded[i] = perm[i] XOR perm[i + 1]. For example, if perm = [1,3,2], then encoded = [2,1].

Given the encoded array, return the original array perm. It is guaranteed that the answer exists and is unique.

 */
class Solution {
public:
    vector<int> decode(vector<int>& v) {
        int x = 0;
        for(auto &i: v)
            x = (x^i);
        // cout<<x<<" ";
        vector<int> tmp = v;
        for(int i = 1; i < v.size(); i++){
            tmp[i] = (tmp[i-1]^v[i]);
        }
        for(int i = 1; i<= v.size()+1; i++){
            if(i <= v.size()){
                x = (x^tmp[i-1]);
            }
            // cout<<x<<" ";
            x ^= i;
        }
        // cout<<x;
        vector<int> ans = {x};
        for(int i = v.size()-1; i>= 0; i--){
            ans.push_back(ans.back()^v[i]);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};