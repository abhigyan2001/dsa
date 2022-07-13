#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& nums) {
        unordered_map<int,vector<int>> diags;
        int maxdiag = 0;
        for(int i=0; i<nums.size(); i++){
            for(int j=0; j<nums[i].size(); j++){
                diags[i+j].push_back(nums[i][j]);
                maxdiag = max(i+j,maxdiag);
            }
        }
        vector<int> ans;
        for(int i=0; i<=maxdiag; i++){
            ans.insert(ans.end(),diags[i].rbegin(),diags[i].rend());
        }
        return ans;
    }
};