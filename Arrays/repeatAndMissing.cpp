#include<bits/stdc++.h>
using namespace std;
class Solution{
public:
    vector<int> Solution::repeatedNumber(const vector<int> &A) {
        long long n=A.size();
        long long a, b;
        long long BminusA=n*(n+1)/2;
        long long BplusA=n*(2*n+1)*(n+1)/6;
        for(int i=0; i<n; i++){
            BminusA -= (long long)A[i];
            BplusA -= (long long)A[i]*(long long)A[i];
        }
        //cout << AminusB << endl;
        //cout << AplusB << endl;
        //cout << AplusB << endl;
        b = (BplusA/BminusA+BminusA)/2;
        a =  b - BminusA;
        return {(int)a,(int)b};
    }
};