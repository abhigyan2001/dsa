#include<vector>
#include<string>
#include<unordered_map>
#include<algorithm>
using namespace std;
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(string str: strs){
            string srt = str;
            sort(srt.begin(),srt.end());
            mp[srt].push_back(str);
        }
        vector<vector<string>> ans;
        for(auto a: mp){
            ans.push_back(a.second);
        }
        return ans;
    }
};