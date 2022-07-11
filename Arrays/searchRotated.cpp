#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0,h=nums.size()-1,mid;
        //cout << "h" << h << endl;
        while(l<=h){
            mid = l+(h-l)/2;
            //cout << "mid" << mid << endl;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[mid]>=nums[l]){
                if(nums[mid]>=target && target>=nums[l]){
                    h=mid-1;
                    //cout << "h" << h << endl;
                }
                else{
                    l=mid+1;
                    //cout << "l" << l << endl;
                }
            }
            else{
                if(nums[mid]<=target && target<=nums[h]){
                    l=mid+1;
                    //cout << "l" << l << endl;
                }
                else{
                    h=mid-1;
                    //cout << "h" << h << endl;
                }
            }
        }
        return -1;
    }
};