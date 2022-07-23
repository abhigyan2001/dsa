#include<vector>
#include<iostream>
using namespace std;


// } Driver Code Ends
#define ll long long 
class Solution{
  public:
    // Function to find floor of x
    // n: size of vector
    // x: element whose floor is to find
    int findFloor(vector<ll> v, ll n, ll x){
        if(v[n-1]<x) return (int)n-1;
        if(v[0]>x) return -1;
        int l=0,r=(int)n-1,mid=l+(r-l)/2;
        while(l<=r){
            mid = l+(r-l)/2;
            if(v[mid]==x) return mid;
            else if(v[mid]<x){
                if(mid+1<n) {
                    if(v[mid+1]>x) return mid;
                    else l = mid+1;
                }
            }
            else if(v[mid]>x){
                r = mid-1;
            }
        }
        return mid;
    }
};


//{ Driver Code Starts.

int main() {
	
	ll t;
	cin >> t;
	
	while(t--){
	    ll n;
	    cin >> n;
	    ll x;
	    cin >> x;
	    
	    vector<ll> v;
	    
	    for(ll i = 0;i<n;i++){
	        ll temp;
	        cin >> temp;
	        v.push_back(temp);
	    }
	    Solution obj;
	    cout << obj.findFloor(v, n, x) << endl;
	   
	}
	
	return 0;
}
// } Driver Code Ends