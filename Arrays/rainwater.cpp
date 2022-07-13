#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    int trap(vector<int>& height) {
        int n=height.size();
        //vector<int> hmaxL(n,0), hmaxR(n,0);
        int l=0, r=height.size()-1;
        int lmax=height[l], rmax=height[r];
        int ans=0;
        while(l<r){
            if(height[l]<height[r]){
                if(height[l]>=lmax){
                    lmax = height[l];
                }
                else{
                    ans+=(lmax-height[l]);
                }
                l++;
            }
            else{
                if(height[r]>=rmax){
                    rmax = height[r];
                }
                else{
                    ans+=(rmax-height[r]);
                }
                r--;
            }
        }
        return ans;
    }
}