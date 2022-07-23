#include<vector>
#include<string>
#include<stack>
//#include<algorithm>
using namespace std;
class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<string> s;
        int op1, op2;
        for(string tk: tokens){
            if(tk=="+"){
                op2 = stoi(s.top());
                s.pop();
                op1 = stoi(s.top());
                s.pop();
                s.push(to_string(op1 + op2));
            }
            else if(tk=="-"){
                op2 = stoi(s.top());
                s.pop();
                op1 = stoi(s.top());
                s.pop();
                s.push(to_string(op1 - op2));
            }
            else if(tk=="*"){
                op2 = stoi(s.top());
                s.pop();
                op1 = stoi(s.top());
                s.pop();
                s.push(to_string(op1 * op2));
            }
            else if(tk=="/"){
                op2 = stoi(s.top());
                s.pop();
                op1 = stoi(s.top());
                s.pop();
                s.push(to_string(op1 / op2));
            }
            else{
                s.push(tk);
            }
        }
        return stoi(s.top());
    }
};