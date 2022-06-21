#include <iostream>
#include <bits/stdc++.h>
class Solution {
public:
    bool isValid(string s) {
        stack<char> x;
        unordered_map<char,char> rev({{'}','{'},{']','['},{')','('}});
        unordered_map<char,bool> fwd({{'{',true},{'[',true},{'(',true},{'}',false},{']',false},{')',false}});
        for(int i = 0; i < s.size(); i++){
            if(fwd[s[i]]){
                x.push(s[i]);
            }
            else if(fwd[s[i]]==false && (x.size()==0 || rev[s[i]]!=x.top())){
                return false;
            }
            else if(rev[s[i]] == x.top()){
                x.pop();
            }
        }
        if(x.size()==0){
            return true;
        }
        return false;
    }
};