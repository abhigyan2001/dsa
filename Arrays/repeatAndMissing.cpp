#include<vector>
#define ll long long
using namespace std;
class Solution{
public:
    vector<int> Solution::repeatedNumber(const vector<int> &A) {
        ll n=A.size();
        ll a, b;
        ll BminusA=n*(n+1)/2;
        ll BplusA=n*(2*n+1)*(n+1)/6;
        for(int i=0; i<n; i++){
            BminusA -= (ll)A[i];
            BplusA -= (ll)A[i]*(ll)A[i];
        }
        //cout << AminusB << endl;
        //cout << AplusB << endl;
        //cout << AplusB << endl;
        b = (BplusA/BminusA+BminusA)/2;
        a =  b - BminusA;
        return {(int)a,(int)b};
    }
};