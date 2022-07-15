#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        // O(n*log(n)) [worst case] solution
        
        sort(nums.begin(),nums.end());
        return nums[nums.size()-k];
    }
    int findKthLargest2(vector<int>& nums, int k){
        // O(n) [average] O(n^2) [worst case] solution
        
        return quickSelect(nums, 0, nums.size()-1, k);
    }
    int quickSelect(vector<int>& nums, int low, int high, int k){
        int pivot = low;
        for(int i=low; i<high; i++){
            if(nums[i]<=nums[high]){
                swap(nums[i],nums[pivot]);
                pivot++;
            }
        }
        swap(nums[pivot],nums[high]);
        int count = high - pivot + 1;
        if(count == k) return nums[pivot];
        else if(count > k) return quickSelect(nums, pivot+1, high, k);
        else return quickSelect(nums, low, pivot-1, k-count);
    }
};