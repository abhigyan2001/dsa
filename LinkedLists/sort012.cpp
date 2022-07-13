using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(nullptr) {}
};

class Solution
{
    public:
    //Function to sort a linked list of 0s, 1s and 2s.
    Node* segregate(Node *head) {
        int zc=0, oc=0, tc=0;
        while(head){
            if(head->data==0){
                zc++;
            }
            if(head->data==1){
                oc++;
            }
            if(head->data==2){
                tc++;
            }
            head = head->next;
        }
        Node* start;
        Node* curr;
        
        if(zc>0){
            start=new Node(0);
            zc--;
        }
        else if(oc>0){
            start=new Node(1);
            oc--;
        }
        else if(tc>0){
            start=new Node(2);
            tc--;
        }
        else return nullptr;
        
        curr = start;
        
        for(int i=0; i<zc; i++){
            curr->next=new Node(0);
            curr = curr->next;
        }
        for(int i=0; i<oc; i++){
            curr->next=new Node(1);
            curr = curr->next;
        }
        for(int i=0; i<tc; i++){
            curr->next=new Node(2);
            curr = curr->next;
        }
        return start;
    }
};