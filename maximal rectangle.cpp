/*Maximal Rectangle

Given a rows x cols binary matrix filled with 0's and 1's, find the largest rectangle containing only 1's and return its area.*/

class Solution {
public:
    int largestRectangleArea(vector<int>& a) {
        int n=a.size();
        vector<int> left(n,0);
        vector<int> right(n,n-1);
        stack<int> st;
        for(int i=0;i<n;i++){
            while(!st.empty() and a[st.top()]>=a[i]) {
                st.pop();
            }
            if(!st.empty()) left[i]=st.top()+1;
            st.push(i);
        }
        while(!st.empty()) st.pop();
         for(int i=n-1;i>=0;i--){
            while(!st.empty() and a[st.top()]>=a[i]) {
                st.pop();
            }
            if(!st.empty()) right[i]=st.top()-1;
            
            st.push(i);
        }
        int area=0;
        for(int i=0;i<n;i++){
            int temp=(right[i]-left[i]+1)*a[i];
            area=max(area,temp);
        }
        return area;
    }
    int maximalRectangle(vector<vector<char>>& a) {
        int n=a.size();
        int m=a[0].size();
    //     int area=0;
    //     vector<int> h(m,0);
    //     for(int i=0;i<n;i++){
    //         for(int j=0;j<m;j++){
    //             if(a[i][j]==1) h[j]++;
    //             else h[j]=0;
    //         }
    //         int temp=largestRectangleArea(h);
    //         area=max(area,temp);
    //     }
    // return area;
    int maxArea = 0;
    vector<int> height(m, 0);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (a[i][j] == '1') height[j]++;
            else height[j] = 0;
        }
        int area = largestRectangleArea(height);
        maxArea = max(maxArea, area);
    }
    return maxArea;
    }
};