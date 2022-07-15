#include<vector>
using namespace std;
class Solution {
public:
    int findMin(vector<int>& nums) {
        int n = nums.size();
        // return the only term if it is of length 1:
        if(n==1) return nums[0];
        // checking if the first term is the answer:
        if(nums[0]<nums[1] && nums[0]<nums[n-1]) return nums[0];
        // checking if the last term is the answer:
        if(nums[n-1]<nums[0] && nums[n-1]<nums[n-2]) return nums[n-1];
        // binary searching for the turning point in array
        int l=1, r=n-2, mid;
        while(l<=r){
            mid = l+(r-l)/2;
            if(nums[mid] < nums[mid-1]){
                return nums[mid];
            }
            else if(nums[r+1] < nums[mid]){
                l = mid+1;
            }
            else if(nums[l-1] > nums[mid]){
                r = mid-1;
            }
        }
        return -1;
    }
};