class Solution {
public:
    bool isPalindrome(string s) {
        int n = s.length();
        string ret ="";
        for(int i=0; i<n; i++){
            if(iswalnum(s[i])){
                ret+=tolower(s[i]);
            }
        }
        int n1 = ret.length();
        for(int i=0; i<n1; i++){
            if(ret[i]!=ret[n1-i-1]){
                return false;
            }
        }
        return true;
    }
};