#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    bool containsDuplicate(vector<int>& nums) {
        unordered_set<int> stuff;
        for(int i = 0; i < nums.size(); i++){
            if(stuff.find(nums[i])==stuff.end()){
                stuff.insert(nums[i]);
            }
            else{
                return true;
            }
        }
        return false;
    }
};