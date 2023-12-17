class Solution {
public:
    int jump(vector<int>& a) {
        int n=a.size();
       
        int l=0;
        int r=0;
        int jump=0;
        while(r<=n-2){
           
            int farthest=0;
            
            for(int j=l;j<=r;j++){
                farthest=max(farthest,a[j]+j);
            }
            l=r+1;
            r=farthest;
            jump++;
        }
        return jump;
    }
};