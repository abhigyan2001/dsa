#include<vector>
#include<algorithm>
#define ll long long
using namespace std;
class Solution{
    public:
    long long findMinDiff(vector<ll> a, ll n, ll m){
        ll mindiff = LLONG_MAX;
        ll curdiff = 0;
        sort(a.begin(),a.end());
        // for(int i = 0; i < n; i++){
        //     cout << a[i] << endl;
        // }
        for(int i = 0; i <= n-m; i++){
            curdiff = a[m+i-1]-a[i];
            if(curdiff < mindiff){
                mindiff = curdiff;
            }
        }
        return mindiff;
    }
};