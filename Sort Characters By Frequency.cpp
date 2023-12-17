/*Sort Characters By Frequency

Given a string s, sort it in decreasing order based on the frequency of the characters. The frequency of a character is the number of times it appears in the string.

Return the sorted string. If there are multiple answers, return any of them.*/

class Solution {
public:
    static bool cmp(pair<char,int> &a,pair<char,int> &b){
        return a.second>b.second;
    }
    string frequencySort(string s) {
        unordered_map<char,int> m;
        for (int i=0;i<s.length();i++){
            m[s[i]]++;
        }
        vector<pair<char,int>> cnt;
        for (auto &p:m){
            cnt.push_back(p);
        }
        sort(cnt.begin(),cnt.end(),cmp);
        
        for (auto k: cnt){
            cout<<k.first<<" "<<k.second<<endl;
        }
        int k=0;
        for (auto m: cnt){
            for (int j=1;j<=m.second;j++){
                s[k++]=m.first;
            }
        }
        return s;
    }
};
