// Initial Template for C++

#include<iostream>
#include<queue>
#include<stack>
using namespace std;
queue<int> modifyQueue(queue<int> q, int k);
int main() {
    int t;
    cin >> t;
    while (t-- > 0) {
        int n, k;
        cin >> n >> k;
        queue<int> q;
        while (n-- > 0) {
            int a;
            cin >> a;
            q.push(a);
        }
        queue<int> ans = modifyQueue(q, k);
        while (!ans.empty()) {
            int a = ans.front();
            ans.pop();
            cout << a << " ";
        }
        cout << endl;
    }
}
// } Driver Code Ends


// User function Template for C++

// Function to reverse first k elements of a queue.
queue<int> modifyQueue(queue<int> q, int k) {
    stack<int> frst;
    queue<int> last;
    for(int i=0; i<k; i++){
        frst.push(q.front());
        q.pop();
    }
    while(q.size()!=0){
        last.push(q.front());
        q.pop();
    }
    for(int i=0; i<k; i++){
        q.push(frst.top());
        frst.pop();
    }
    while(last.size()!=0){
        q.push(last.front());
        last.pop();
    }
    return q;
}