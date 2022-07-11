#include <bits/stdc++.h>
using namespace std;

// User function Template for C++

class Solution{
public:
    int knapSack(int N, int W, int val[], int wt[])
    {
        // vector<vector<int>> memo(N+1,vector<int>(W+1,0));
        vector<int> memo(W+1,0);
        // int remWt=W, curVal=0, maxVal=0;
        for(int i=0; i<N; i++){
            for(int j=wt[i]; j<=W; j++){
                // if(wt[i-1]<=j){
                //     int a = val[i-1]+memo[i][j-wt[i-1]];
                //     int b = memo[i-1][j];
                //     memo[i][j]= a > b ? a : b;
                // }
                // else{
                //     memo[i][j]= memo[i-1][j];
                // }
                memo[j]=max(memo[j-wt[i]]+val[i],memo[j]);
            }
        }
        return memo[W];
    }
};

// { Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int N, W;
        cin>>N>>W;
        int val[N], wt[N];
        for(int i = 0;i < N;i++)
            cin>>val[i];
        for(int i = 0;i < N;i++)
            cin>>wt[i];
        
        Solution ob;
        cout<<ob.knapSack(N, W, val, wt)<<endl;
    }
    return 0;
}  // } Driver Code Ends