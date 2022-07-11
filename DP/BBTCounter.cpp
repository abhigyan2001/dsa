#include<bits/stdc++.h>
using namespace std;

class Solution {
  public:
    long long int countBT(int h) { 
        long long int count[h+1];
        int mod = 1000000007;
        count[0] = 1;
        count[1] = 1;
        for(int i = 2; i <= h; i++){
            long long int x = (count[i-1]*(count[i-1]+2*count[i-2]));
            //cout << x << endl;
            count[i] = (long long int)x%mod;
        }
        return count[h];
    }
};