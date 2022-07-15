#include<string>
#include<vector>
#include<iostream>
using namespace std;
class Solution {
public:
    string longestPalindrome(string s) {
        int n = s.length();
        // handling some edge cases
        if(n==1) return string(1,s[0]); 
        if(n==2) {
            if(s[0]==s[1]) return s;
            else return string(1,s[0]);
        }
        // Manacher's Algorithm
        vector<int> radii(2*n-1,0);
        string s1 = "";
        s1 += s[0];
        for(int i=1; i<n; i++){
            s1 += "|";
            s1 += s[i];
        }
        cout << s1 <<endl;
        int center = 0, radius = 0;
        int n1 = s1.length();
        while(center < n1){
            while(center-(radius+1)>=0 && center+(radius+1)<n1 && s1[center+(radius+1)]==s1[center-(radius+1)]){
                radius++;
            }
            radii[center] = radius;
            int oldcenter = center;
            int oldradius = radius;
            center++;
            radius = 0;
            while(center <= oldcenter + oldradius){
                int mirroredCenter = oldcenter - (center-oldcenter);
                int maxMirroredRadius = oldcenter - center + oldradius;
                if(radii[mirroredCenter] < maxMirroredRadius){
                    radii[center] = radii[mirroredCenter];
                    center++;
                }
                else if(radii[mirroredCenter] > maxMirroredRadius){
                    radii[center] = maxMirroredRadius;
                    center++;
                }
                else{
                    radius = maxMirroredRadius;
                    break;
                }
            }
        }
        int maxRad = 0, maxPos=0;
        for(int i=0; i<radii.size(); i++){
            int rad = radii[i];
            cout << rad << " ";
            if(rad>maxRad){
                maxRad = rad;
                maxPos = i;
            }
            if(rad == maxRad){
                if(i%2!=0) maxPos=i;
            }
        }
        cout << endl;
        string ret = "";
        cout << maxPos << " " << maxRad <<endl;
        for(int i=maxPos-maxRad; i<=maxPos+maxRad; i++){
            if(s1[i]!='|') ret+=s1[i];
        }
        cout << ret << endl;
        return ret;
    }
};