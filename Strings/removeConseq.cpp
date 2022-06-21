#include<bits/stdc++.h>
using namespace std;
class Solution{
    public:
    string removeConsecutiveCharacter(string s)
    {
        string ret = "";
        bool rpt=false;
        int n = s.length();
        if(n==1) return s;
        for(int i=1; i<n; i++){
            if(s[i]==s[i-1]){
                rpt = true;
            }
            else if(s[i]!=s[i-1]){
                rpt = false;
                ret += s[i-1];
            }
            if(i==n-1){
                ret += s[i];
            }
        }
        return ret;
    }
};