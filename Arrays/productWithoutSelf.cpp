#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> prods(n);
        prods[0]=1;
        for(int i=1; i<n; i++){
            prods[i] = prods[i-1] * nums[i-1];
        }
        int product = 1;
        for(int i=n-2; i>=0; i--){
            product *= nums[i+1];
            prods[i] *= product;
        }
        return prods;
    }
};