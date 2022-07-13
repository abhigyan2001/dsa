#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends

class Solution{
	
	public:
	vector<int> downwardDigonal(int n, vector<vector<int>> A)
	{
		vector<int> ans(n*n);
		int i=0,x=0,y=0,s=0;
		while(i<n*n){
		    ans[i] = A[y][x];
		    if(x==0 && y!=n-1){
		        s++;
		        x = s;
		        y = 0;
		    }
		    else if(y==n-1){
		        s++;
		        y = s-(n-1);
		        x = n-1;
		    }
		    else{
		        x--;
		        y++;
		    }
		    i++;
		}
		return ans;
	}

};

// { Driver Code Starts.



int main()
{

    
    int t;
    cin >> t;
    while(t--) 
    {
        int n;
        cin >> n;

        vector<vector<int>> A(n, vector<int>(n));

        for(int i = 0; i < n; i++)
        	for(int j = 0; j < n; j++)
        		cin >> A[i][j];

        Solution obj;
        vector<int> ans = obj.downwardDigonal(n, A);

        for(auto i:ans)
        	cout << i << " ";

	    cout << "\n";
    }

    return 0;
}
  // } Driver Code Ends