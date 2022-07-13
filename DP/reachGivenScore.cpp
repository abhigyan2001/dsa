// Driver Code
#include<iostream>
#include<vector>
#define ll long long
using namespace std;

 // } Driver Code Ends
// Complete this function
ll count(ll n){
	vector<ll> table(n+1,0);
	ll i;
	table[0]=1;                 // If 0 sum is required number of ways is 1.
	for(i=3; i<=n; i++){
	    table[i]+=table[i-3];
	}
	for(i=5; i<=n; i++){
	    table[i]+=table[i-5];
	}
	for(i=10;i<=n; i++){
	    table[i]+=table[i-10];
	}
	return table[n];
}

// { Driver Code Starts.



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		cout<<count(n)<<endl;
	}
	return 0;
}  // } Driver Code Ends