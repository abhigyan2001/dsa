#include<string>
using namespace std;
class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        int l = 0, r = 0, maxsize = 0, t;
        int lets[256] = {0};
        while(r < s.length()){
            lets[s[r]]++;
            while(lets[s[r]] > 1){
                lets[s[l]]--;
                l++;
            }
            t = r-l+1;
            maxsize = maxsize > t ? maxsize : t;
            r++;
        }
        return maxsize;
    }
};