#include<queue>
#include<algorithm>
using namespace std;
class MyStack {
public:
    queue<int> q1;
    queue<int> q2;
    MyStack() {
        //empty
    }
    
    void push(int x) {
        q1.push(x);
    }
    
    int pop() {
        swap(q1,q2);
        while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
        }
        int ret = q2.front();
        q2.pop();
        return ret;
    }
    
    int top() {
        if(q2.empty()){
            swap(q1,q2);
        }
        while(q2.size()>1){
            q1.push(q2.front());
            q2.pop();
        }
        int ret = q2.front();
        q1.push(ret);
        q2.pop();
        return ret;
    }
    
    bool empty() {
        return q1.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */