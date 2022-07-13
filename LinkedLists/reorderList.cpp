#include<stack>
using namespace std;

// Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode(int x) : val(x), next(NULL) {}
};

class Solution {
public:
    void reorderList1(ListNode* head) {
        // O(n^2) time, O(1) space
        ListNode *curr=head, *last, *iter=head, *strt=head;
        int n=0;
        while(iter->next){
            n++;
            iter=iter->next;
        }
        n++;
        int i=0,j;
        while(i<n/2){
            j=0;
            iter = head;
            while(j<n-1){
                iter=iter->next;
                j++;
            }
            last = iter;
            curr = strt->next;
            strt->next = last;
            last->next = curr;
            strt = curr;
            i++;
        }
        i = 0;
        iter = head;
        while(i<n-1){
            iter = iter->next;
            i++;
        }
        iter->next = nullptr;
    }
    
    void reorderList2(ListNode* head) {
        // O(n) solution, O(n) space
        stack<ListNode*> s;
        int n=0;
        ListNode* curr = head;
        while(curr){
            n++;
            curr = curr->next;
            if(curr) s.push(curr);
        }
        int i=0;
        ListNode *strt = head, *last;
        for(i=0;i<n/2;i++){
            last = s.top();
            s.pop();
            curr = strt->next;
            strt->next = last;
            last->next = curr;
            strt = curr;
        }
        i=0;
        curr = head;
        while(i<n){
            i++;
            curr=curr->next;
            if(i==n-1){
                curr->next=nullptr;
            }
        }
    }
};