#include <bits/stdc++.h>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    bool hasCycle1(ListNode *head) {
        // O(n) time O(n) aux space
        int pos=0;
        unordered_set<ListNode*> visited;
        ListNode* curr = head;
        while(curr!=nullptr){
            if(visited.find(curr)!=visited.end()){
                return true;
            }
            else{
                visited.insert(curr);
                curr = curr->next;
            }
        }
        return false;
    }
    bool hasCycle2(ListNode *head){
        // O(n) time O(1) aux space
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast!=nullptr && fast->next!=nullptr){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast){
                return true;
            }
        }
        return false;
    }
};