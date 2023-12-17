/* Minimum Time to Make Rope Colorful

Alice has n balloons arranged on a rope. You are given a 0-indexed string colors where colors[i] is the color of the ith balloon.

Alice wants the rope to be colorful. She does not want two consecutive balloons to be of the same color, so she asks Bob for help. Bob can remove some balloons from the rope to make it colorful. You are given a 0-indexed integer array neededTime where neededTime[i] is the time (in seconds) that Bob needs to remove the ith balloon from the rope.

Return the minimum time Bob needs to make the rope colorful.*/

class Solution {
public:
    int minCost(string colors, vector<int>& time) 
    {
        int count=0;
        for(int i=0;i<colors.size()-1;i++)
        { 
            priority_queue<int> q;
            // cout<<i<<" ";
            bool check=0;
            while(i<colors.size() && colors[i]==colors[i+1])
            {
                q.push(time[i]);  
                i+=1;
                check=1;
            }
            if(check)
            {
			// only when , we out from above loop thenwe add last one more char time to priority_queue.
                q.push(time[i]);  
            }
            if(q.size()>0)
            {
                q.pop();
            }
            while(q.size()>0)
            {
                count+=q.top();
                q.pop();
            }
            
        }
        return count;
    }
};