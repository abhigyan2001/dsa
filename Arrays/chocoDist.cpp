#include <bits/stdc++.h>
class Solution{
    public:
    long long findMinDiff(vector<long long> a, long long n, long long m){
        long long mindiff = LLONG_MAX;
        long long curdiff = 0;
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