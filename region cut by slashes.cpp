/*Regions Cut By Slashes

An n x n grid is composed of 1 x 1 squares where each 1 x 1 square consists of a '/', '\', or blank space ' '. These characters divide the square into contiguous regions.

Given the grid grid represented as a string array, return the number of regions.

Note that backslash characters are escaped, so a '\' is represented as '\\'.*/

class Solution {
public:
    class DisjointSet {
    public: 
        vector<int> rank, parent, size;
        DisjointSet(int n) {
            rank.resize(n+1, 0); 
            parent.resize(n+1);
            size.resize(n+1); 
            for(int i = 0;i<=n;i++) {
                parent[i] = i; 
                size[i] = 1; 
            }
        }
        int findparent(int node) {
            if(node == parent[node])
                return node; 
            return parent[node] = findparent(parent[node]); 
        }
        void unionByRank(int x, int y) {
            int u = findparent(x); 
            int v = findparent(y); 
            if(u == v) return; 
            if(rank[u] < rank[v]) {
                parent[u] = v; 
            }
            else if(rank[v] < rank[u]) {
                parent[v] = u; 
            }
            else {
                parent[v] = u; 
                rank[u]++; 
            }
        }
        void unionBySize(int x, int y) {
            int u = findparent(x); 
            int v = findparent(y); 
            if(u == v) return; 
            if(size[u] < size[v]) {
                parent[u] = v; 
                size[v] += size[u]; 
                size[u]=1;
            }
            else {
                parent[v] = u;
                size[u] += size[v];
            }
        }
    }; 
    int regionsBySlashes(vector<string>& grid) {
      int m=grid.size();
      int n=grid[0].size();;
      
      int maxrow=m+1;
      int maxcol=n+1;

      DisjointSet ds(maxrow*maxcol);

      int ans=1;

      for(int i=0;i<maxrow;i++){
          for(int j=0;j<maxcol;j++){
              if( i==0 || j==0 || i==maxrow-1 || j==maxcol-1 ){
                  int rownode=i*maxrow+j;
                  if(rownode!=0)ds.unionBySize(0,rownode);
              }
          }
      }  
      for(int i=0;i<m;i++){
          for(int j=0;j<n;j++){
              if(grid[i][j]=='/'){
                  int x1=i;
                  int y1=j+1;
                  int x2=i+1;
                  int y2=j;
                  int node1=x1*maxrow+y1;
                  int node2=x2*maxrow+y2;
                  if(ds.findparent(node1)!=ds.findparent(node2)){
                      ds.unionBySize(node1,node2);
                  }else{
                      ans++;
                  }
              }else if(grid[i][j]=='\\'){
                  int x1=i;
                  int y1=j;
                  int x2=i+1;
                  int y2=j+1;
                  int node1=x1*maxrow+y1;
                  int node2=x2*maxrow+y2;
                  if(ds.findparent(node1)!=ds.findparent(node2)){
                      ds.unionBySize(node1,node2);
                  }else{
                      ans++;
                  }
              }
          }
      } 
      return ans;
    }
};