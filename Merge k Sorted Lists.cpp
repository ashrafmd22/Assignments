/*Merge k Sorted Lists

You are given an array of k linked-lists lists, each linked-list is sorted in ascending order.

Merge all the linked-lists into one sorted linked-list and return it.*/

/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
    
public:
    struct mycmp{
    bool operator()( ListNode* a, ListNode* b){
        return a->val>b->val;
    }
};
    ListNode* mergeKLists(vector<ListNode*>& lists) {
        priority_queue<ListNode*,vector<ListNode*>, mycmp > p;
        for(int i=0;i<lists.size();i++){
           if(lists[i]!=NULL) p.push(lists[i]);
        }
        ListNode* head= NULL;
        ListNode* tail= NULL;
        while(!p.empty()){
            ListNode* temp = p.top();
            p.pop();
            if(head==NULL){
                head=tail=temp;
            }
            else{
            
                tail->next=temp;
                tail=temp;
            }
            if(temp->next!=NULL) p.push(temp->next);
                
        }
        return head;
    }
};