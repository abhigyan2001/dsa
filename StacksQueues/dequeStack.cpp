#include<iostream>
#include<deque>
using namespace std;
class Stack{
public:
    // Initialize your data structure.
    deque<int> d;
    Stack() {
    }

    // Pushes 'X' into the stack. Returns true if it gets pushed into the stack, and false otherwise.
    bool push(int x){
        d.push_front(x);
        return true;
    }

    // Pops top element from Stack. Returns -1 if the stack is empty, otherwise returns the popped element.
    int pop(){
        if(d.size()==0) return -1;
        int ret = d.front();
        d.pop_front();
        return ret;
    }

    // Returns the topmost element of the stack. In case the stack is empty, it returns -1.
    int top(){
        if(d.size()==0) return -1;
        return d.front();
    }

    // Returns true if the stack is empty, otherwise false.
    bool isEmpty(){
        return d.empty();
    }

    // Returns the number of elements currently present in the stack.
    int size(){
        return d.size();
    }
};