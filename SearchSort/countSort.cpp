//Initial Template for C++

#include<iostream>
#include<vector>

using namespace std;
#define RANGE 255


// } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    //Function to arrange all letters of a string in lexicographical 
    //order using Counting Sort.
    string countSort(string arr){
        int N = arr.length();
        vector<int> cnts(26,0);
        for(int i=0; i<N; i++){
            cnts[arr[i]-97]++;
        }
        for(int i=1; i<26; i++){
            cnts[i]+=cnts[i-1];
        }
        string ret(N,0);
        int cnta = 0;
        for(int i=0; i<N; i++){
            if(arr[i]=='a') {
                ret[cnta]='a';
                cnta++;
            }
            else{
                ret[cnts[arr[i]-97-1]]=arr[i];
                cnts[arr[i]-97-1]++;
            }
        }
        return ret;
    }
};


//{ Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        string arr;
        cin>>arr;
        Solution obj;
        cout<<obj.countSort(arr)<<endl;
    }
    return 0;
}

// } Driver Code Ends