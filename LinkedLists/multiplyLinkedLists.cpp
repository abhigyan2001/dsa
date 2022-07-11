#include <bits/stdc++.h>
using namespace std;

struct Node {
    int data;
    Node *next;
    Node(int x) : data(x), next(NULL) {}
};

long long multiplyTwoLists (Node* l1, Node* l2)
{
    int mod = 1000000007;
    long long n1=0, n2=0;
    Node* p;
    p = l1;
    while(p){
        n1 = 10*n1%mod + p->data;
        p = p->next;
    }
    p = l2;
    while(p){
        n2 = 10*n2%mod + p->data;
        p = p->next;
    }
    return ((n1%mod)*(n2%mod))%mod;
}