#include<string>
#include<vector>
#include<algorithm>
using namespace std;
class Solution {
public:
    string longestCommonPrefix(vector<string>& strs) {
        sort(strs.begin(), strs.end(), compare);
        int n = strs[0].length();
        string ret = "";
        char curlet;
        for(int i = 0; i < n; i++){
            curlet = strs[0][i];
            for(int j=0; j < strs.size(); j++){
                if(curlet != strs[j][i]){
                    return ret;
                }
            }
            ret+=curlet;
        }
        return ret;
    }
    static bool compare(const string& s1, const string& s2){
        return s1.length() < s2.length();
    }
};