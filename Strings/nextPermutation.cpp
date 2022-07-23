// Initial Template for C++

#include<vector>
#include<iostream>
#include<algorithm>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
public:
    vector<int> nextPermutation(int N, vector<int> arr){
        int k,l;
        for(k=N-2; k>=0; k--){
            if(arr[k]<arr[k+1]) break;
        }
        if(k==-1){
            reverse(arr.begin(),arr.end());
            return arr;
        }
        for(l=N-1; l>=0; l--){
            if(arr[l]>arr[k]) break;
        }
        swap(arr[l],arr[k]);
        reverse(arr.begin()+k+1,arr.end());
        return arr;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<int> arr(N);
        for(int i = 0;i < N;i++)
            cin>>arr[i];
        
        Solution ob;
        vector<int> ans = ob.nextPermutation(N, arr);
        for(int u: ans)
            cout<<u<<" ";
        cout<<"\n";
    }
    return 0;
}
// } Driver Code Ends