/* Task Scheduler

Given a characters array tasks, representing the tasks a CPU needs to do, where each letter represents a different task. Tasks could be done in any order. Each task is done in one unit of time. For each unit of time, the CPU could complete either one task or just be idle.

However, there is a non-negative integer n that represents the cooldown period between two same tasks (the same letter in the array), that is that there must be at least n units of time between any two same tasks.

Return the least number of units of times that the CPU will take to finish all the given tasks.

 */

 class Solution {
public:
    int leastInterval(vector<char>& a, int n) {
        unordered_map<char,int> mp;
        for(int i=0 ; i<a.size();i++){
            mp[a[i]]++;
        }
        priority_queue<int> pq;
        auto it=mp.begin();
        while(it!=mp.end()){
            pq.push(it->second);
            it++;
        }
        int cycle=n+1;
        int ans=0;
        while(!pq.empty()){
            vector<int> temp;
            int time=0;
            for(int i=0;i<n+1;i++){
              if(!pq.empty()) { temp.push_back(pq.top()-1);
                pq.pop();
                time++;}
            }
            for(int i=0;i<temp.size();i++){
               if(temp[i]!=0) pq.push(temp[i]);
            }
            ans+=pq.empty()?time:cycle;
        }
        return ans;
    }
};