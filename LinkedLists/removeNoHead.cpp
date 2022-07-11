#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

class Solution
{
    public:
    //Function to delete a node without any reference to head pointer.
    void deleteNode(Node *del)
    {
        // method 1
        Node* nextNode = del->next;
        del->data = nextNode->data;
        del->next = nextNode->next;
    }
    void deleteNode2(Node *del)
    {
        // method 2
        *del = *(del->next);
    }

};