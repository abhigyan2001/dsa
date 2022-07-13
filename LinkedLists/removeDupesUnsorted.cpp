#include<unordered_set>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};


class Solution
{
    public:
    //Function to remove duplicates from unsorted linked list.
    Node * removeDuplicates(Node *head) 
    {
        Node* curr = head;
        Node* prev = head;
        unordered_set<int> vals;
        int i=0;
        while(curr){
            if(vals.find(curr->data)!=vals.end()){
                if(curr->next!=nullptr){
                    *curr = *(curr->next);
                }
                else{
                    prev->next = nullptr;
                    break;
                }
            }
            else{
                vals.insert(curr->data);
                prev = curr;
                curr = curr->next;
            }
        }
        return head;
    }
};