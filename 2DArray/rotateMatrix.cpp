#include <bits/stdc++.h>
using namespace std;
class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n = matrix.size();
        int temp = 0;
        
        for(int i=0; i<n/2; i++){
            for(int j=0; j<n; j++){
                if(n%2==0 || (n%2!=0&&i!=n/2)){
                    temp = matrix[i][j];
                    matrix[i][j] = matrix[n-i-1][j];
                    matrix[n-i-1][j] = temp;
                }
            }
        }
        for(int i=0; i<n; i++){
            for(int j=i; j<n; j++){
                temp = matrix[i][j];
                matrix[i][j] = matrix[j][i];
                matrix[j][i] = temp;
            }
        }
    }
};