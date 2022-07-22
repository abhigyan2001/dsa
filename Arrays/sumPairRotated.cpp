#include<vector>
using namespace std;
class Solution{
public:
    int findPairSum(vector<int> arr, int target)
    {
        int i, n=arr.size();
        for(i=0; i<arr.size()-1; i++){
            if(arr[i]>arr[i+1]) break;
        }
        int l = (i+1)%n;
        int r = i;
        while(l!=r){
            int sum = arr[l]+arr[r];
            if(sum == target) return 1;
            else if(sum > target) r = (r+n-1)%n;
            else if(sum < target) l = (l+1)%n;
        }
        return 0;
    }
};