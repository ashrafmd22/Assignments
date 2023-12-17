/*Word Search II

Given an m x n board of characters and a list of strings words, return all words on the board.

Each word must be constructed from letters of sequentially adjacent cells, where adjacent cells are horizontally or vertically neighboring. The same letter cell may not be used more than once in a word.*/

class Node{
    public:
    bool isterminal ;
    Node* child[26];
    Node(){
        isterminal=false;
        for(int i=0;i<26;i++){
            child[i]=NULL;
        }
        
    }
};
void ins(string& a,Node* root){
            for(int i=0;i<a.size();i++){
                if(root->child[a[i]-'a']==NULL){
                    root->child[a[i]-'a']=new Node;
                }
                root=root->child[a[i]-'a'];
            }
            root->isterminal=true;
        }
class Solution {
public:
   /* void dfs(vector<vector<char>>& b,Node* node,int i,int j,string& s, unordered_set<string>& res){
        if(i<0 or j<0 or i>=b.size() or j>=b[0].size()) return ;
        char c=b[i][j];
        if(c=='*') return ;
        b[i][j]='*';
        Node* n=node->child[c-'a'];
        if(n!=NULL){
            string ss=s+c;
            if(n->isterminal==true) res.insert(ss);
            dfs(b,node,i+1,j,ss,res);
            dfs(b,node,i-1,j,ss,res);
            dfs(b,node,i,j+1,ss,res);
            dfs(b,node,i,j-1,ss,res);
         
        }
           b[i][j]=c;
    }*/
     void dfs(vector<vector<char>>& board, int i, int j, Node* trie,  string s,unordered_set<string>& result){
         if(i<0 or j<0 or i>=board.size() or j>=board[0].size())
      {
          return ;
      }
        char c = board[i][j];
        if(c == '$') return;
        board[i][j] = '$';
        Node* t = trie->child[c - 'a'];
        if(t){
            string ss = s + c;
            if(t->isterminal) result.insert(ss);
            dfs(board, i+1, j, t, ss, result);
             dfs(board, i-1, j, t, ss, result);
             dfs(board, i, j+1, t, ss, result);
             dfs(board, i, j-1, t,ss, result);
        }
        board[i][j] = c;
    }
    vector<string> findWords(vector<vector<char>>& b, vector<string>& w) {
        if(w.size()==0) return {};
        Node* node=new Node;
        for(int i=0;i<w.size();i++){
         ins(w[i],node);
        }
        string s="";
        unordered_set<string> res;
        for(int i=0;i<b.size();i++){
            for(int j=0;j<b[0].size();j++){
                dfs(b,i,j,node,s,res);
            }
        }
        vector<string> ans(res.begin(),res.end());
        return ans;
    }
};