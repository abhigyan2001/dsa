#include<vector>
#include<iostream>
using namespace std;
 // } Driver Code Ends
class Solution{
    public:
    int search(vector<int> A, int l, int h, int key){
        if(l>h){
            return -1;
        }
        int find = l+(h-l)/2;
        if(A[find]==key){
            return find;
        }
        else if(A[find]>=A[l]){
            if(A[find]>=key && key>=A[l]){
                return search(A,l,find-1,key);
            }
            else{
                return search(A,find+1,h,key);
            }
        }
        else{
            if(A[find]<=key && key<=A[h]){
                return search(A,find+1,h,key);
            }
            else{
                return search(A,l,find-1,key);
            }
        }
    }
};

// { Driver Code Starts. 
int main() {
    int t;
    cin >> t;
    while(t--){
        int n;
        cin >> n;
        vector<int> A(n);
        for(int i = 0; i < n; i++)
            cin >> A[i];
        int key;
        cin >> key;
        Solution ob;
        cout << ob.search(A, 0, n - 1, key) << endl;
    }
return 0;
}  // } Driver Code Ends