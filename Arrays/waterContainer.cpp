#include<vector>
using namespace std;
class Solution {
public:
    int maxArea(vector<int>& height) {
        int n = height.size();
        int maxAr = 0, curAr;
        int lMax = 0, rMax = n-1;
        maxAr = abs(min(height[rMax],height[lMax])*(rMax-lMax));
        while(lMax < rMax){
            int h = min(height[rMax],height[lMax]);
            curAr = h*(rMax - lMax);
            maxAr = max(curAr,maxAr);
            while(height[lMax] <= h && lMax<rMax) lMax++; //go to lMax+1 once lMax reaches h
            while(height[rMax] <= h && lMax<rMax) rMax--; //go to rMax-1 once rMax reaches h
        }
        return maxAr;
    }
};