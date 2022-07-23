#include<vector>
#include<iostream>
using namespace std;
// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeKLists(vector<ListNode*>& lists) { 
        int numLists = lists.size();
        if(numLists==0) return nullptr;
        vector<ListNode*> currs(numLists);
        currs[0] = lists[0];
        for(int i=0; i<numLists-1; i++){
            currs[i+1] = merge2Lists(currs[i],lists[i+1]);
        }
        return currs[numLists-1];
    }
    ListNode* merge2Lists(ListNode* curr1, ListNode* curr2){
        if(!curr1) return curr2;
        else if(!curr2) return curr1;
        ListNode* curr;
        if(curr1->val < curr2->val){
            curr = curr1;
            curr1 = curr1->next;
        }
        else{
            curr = curr2;
            curr2 = curr2->next;
        }
        ListNode* head = curr;
        while(curr1 && curr2){
            if(curr1->val < curr2->val){
                curr->next = curr1;
                curr1 = curr1->next;
            }
            else{
                curr->next = curr2;
                curr2 = curr2->next;
            }
            curr = curr->next;
        }
        if(!curr1 && curr2){
            curr->next = curr2;
        }
        if(!curr2 && curr1){
            curr->next = curr1;
        }
        return head;
    }
};