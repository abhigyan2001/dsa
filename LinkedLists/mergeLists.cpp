using namespace std;

//Definition for singly-linked list.
struct ListNode {
    int val;
    ListNode *next;
    ListNode() : val(0), next(nullptr) {}
    ListNode(int x) : val(x), next(nullptr) {}
    ListNode(int x, ListNode *next) : val(x), next(next) {}
};

class Solution {
public:
    ListNode* mergeTwoLists(ListNode* l1, ListNode* l2) {
        if(l1==nullptr){
            return l2;
        }
        else if(l2==nullptr){
            return l1;
        }
        ListNode *head, *curr;
        if(l1->val < l2->val){
            curr=l1;
            l1=l1->next;
        }
        else{
            curr=l2;
            l2=l2->next;
        }
        head = curr;
        while(l1!=nullptr && l2!=nullptr){
            if(l1->val < l2->val){
                curr->next=l1;
                l1 = l1->next;
                curr=curr->next;
            }
            else{
                curr->next=l2;
                l2 = l2->next;
                curr=curr->next;
            }
        }
        if(l1==nullptr){
            curr->next=l2;
        }
        else if(l2==nullptr){
            curr->next=l1;
        }
        return head;
    }
};