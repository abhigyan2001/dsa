#include<algorithm>
#include<iostream>
#include<vector>
using namespace std;

// } Driver Code Ends
#define ll long long
class Solution {
  public:
    bool isPossible(vector<ll> a, vector<ll> b, int n, ll k) {
        sort(a.begin(),a.end());
        sort(b.begin(),b.end(),greater<ll>());
        for(int i=0; i<n; i++){
            if(a[i]+b[i]<k){
                return false;
            }
        }
        return true;
    }
};

//{ Driver Code Starts.
int main() {
    ll t;
    cin >> t;
    while (t--) {
        int n;
        ll k;
        cin >> n >> k;
        vector<ll> a(n + 2), b(n + 2);
        for (int i = 0; i < n; i++) cin >> a[i];
        for (int i = 0; i < n; i++) cin >> b[i];
        Solution ob;
        cout << ob.isPossible(a, b, n, k) << endl;
    }
    return 0;
}

// } Driver Code Ends