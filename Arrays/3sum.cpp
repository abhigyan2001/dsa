#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        int target=0, sum, n=nums.size();
        int l=0, r=n-1;
        vector<int> triplet;
        vector<vector<int>> ret;
        sort(nums.begin(),nums.end());
        for(int i=0; i<n;i++){
            target = -nums[i];
            l=i+1;
            r=n-1;
            while(l<r){
                sum=nums[l]+nums[r];
                if(sum<target){
                    l++;
                }
                else if(sum>target){
                    r--;
                }
                else{
                    triplet = {nums[i],nums[l],nums[r]};
                    ret.push_back(triplet);
                    while(l<r && nums[l]==triplet[1]){
                        l++;
                    }
                    while(l<r && nums[r]==triplet[2]){
                        r--;
                    }
                }
            }
            while(i+1<n && nums[i+1]==nums[i]){
                i++;
            }
        }
        return ret;
    }
};