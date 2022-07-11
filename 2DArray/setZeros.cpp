#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void setZeroes(vector<vector<int>>& matrix) {
        int n = matrix.size(), m=matrix[0].size();
        vector<vector<int>> pos;
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(matrix[i][j]==0){
                    pos.push_back({i,j});
                }
            }
        }
        for(int p=0; p<pos.size(); p++){
            int x = pos[p][0], y=pos[p][1];
            cout << x << " " << y << endl;
            for(int i=0; i<n; i++){
                for(int j=0; j<m; j++){
                    if(i==x || j==y) matrix[i][j]=0; 
                }
            }
        }
    }
};