/*Implement Trie (Prefix Tree)

A trie (pronounced as "try") or prefix tree is a tree data structure used to efficiently store and retrieve keys in a dataset of strings. There are various applications of this data structure, such as autocomplete and spellchecker.

Implement the Trie class:

Trie() Initializes the trie object.
void insert(String word) Inserts the string word into the trie.
boolean search(String word) Returns true if the string word is in the trie (i.e., was inserted before), and false otherwise.
boolean startsWith(String prefix) Returns true if there is a previously inserted string word that has the prefix prefix, and false otherwise.*/

struct Node{
    bool isterminal;
    Node* child[26];
    Node(){
        isterminal=false;
        for(int i=0;i<26;i++) child[i]=NULL;
    }
};
class Trie {
    Node* root;
public:
    
    Trie() {
        root= new Node;
    }
    
    void insert(string w) {
        Node* curr=root;
        for(int i=0;i<w.size();i++){
            if(curr->child[w[i]-'a']==NULL){
                curr->child[w[i]-'a']=new Node;
            }
            curr=curr->child[w[i]-'a'];
        }
        curr->isterminal=true;
    }
    
    bool search(string w) {
        Node* curr=root;
     for(int i=0;i<w.size();i++){
            if(curr->child[w[i]-'a']==NULL){
                return false;
            }
            curr=curr->child[w[i]-'a'];
        }
        return curr->isterminal;
        
    }
    
    bool startsWith(string w) {
        Node* curr=root;
     for(int i=0;i<w.size();i++){
            if(curr->child[w[i]-'a']==NULL){
                return false;
            }
            curr=curr->child[w[i]-'a'];
        }
        return true;
        
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */