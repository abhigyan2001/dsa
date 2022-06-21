#include<bits/stdc++.h>

using namespace std;
class Solution {
public:
    bool isAnagram(string s, string t) {
        // Method 1: Using Hash Map
        // O(n) time, O(n) space
        unordered_map<char,int> letters;
        int n = s.length();
        for(int i=0; i<s.length(); i++){
            if(letters.find(s[i])!=letters.end()){
                letters[s[i]]+=1;
            }
            else{
                letters[s[i]]=1;
            }
        }
        for(int i=0; i<t.length(); i++){
            if(letters.find(t[i])!=letters.end()){
                letters[t[i]]-=1;
            }
            else{
                return false;
            }
        }
        for(pair<char,int> p : letters){
            if(p.second!=0){
                return false;
            }
        }
        return true;
    }
    bool isAnagram2(string s, string t) {
        // Method 2: Using size 26 array (for each letter in english) to count letters.
        // O(n) time, O(1) space.
        int counts[26]={0};
        if(s.length()!=t.length()){
            return false;
        }
        for(int i = 0; i < s.length(); i++){
            counts[s[i]-97]++;
            counts[t[i]-97]--;
        }
        for(int i = 0; i < 26; i++){
            if(counts[i]!=0){
                return false;
            }
        }
        return true;
    }
};