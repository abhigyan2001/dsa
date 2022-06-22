#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    bool findPair(int arr[], int size, int n){
        sort(arr,arr+size);
        int i=0,j=1;
        int diff;
        while(i<size&&j<size){
            diff=abs(arr[j]-arr[i]);
            if(diff==n && i<j) return true;
            else if(diff<n) j++;
            else i++;
            if(i==j){i--;j++;}
        }
        return false;
    }
};