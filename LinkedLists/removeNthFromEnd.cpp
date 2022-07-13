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
    ListNode* removeNthFromEnd(ListNode* head, int n) {
        // Solution 1: Using 2 passes
        ListNode* curr = head;
        int len = 0;
        while(curr!=nullptr){
            len++;
            curr=curr->next;
        }
        if(len == n){
            head = head->next;
        }
        curr = head;
        for(int i = 0; i < (len-n); i++){
            if(i==(len-n-1)){
                curr->next = curr->next->next;
                break;
            }
            curr = curr->next;
        }
        return head;
    }
    ListNode* removeNthFromEnd2(ListNode* head, int n) {
        // Solution 2: Using 1 Pass and O(1) extra memory of a pointer lagging n nodes behind the current node
        ListNode *curr = head, *nBack = head;
        int len=1;
        while(curr!=nullptr){
            if(curr->next==nullptr){
                if(len==n){
                    head=head->next;
                    break;
                }
                else{
                    nBack->next = nBack->next->next;
                    break;
                }
            }
            if(len==n){
                nBack = head;
            }
            else if(len>n){
                nBack = nBack->next;
            }
            len++;
            curr = curr->next;
        }
        return head;
    }
};