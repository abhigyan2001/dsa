#include<vector>
using namespace std;
class Solution {
public:
    vector<int> findDiagonalOrder(vector<vector<int>>& mat) {
        int m = mat.size(), n = mat[0].size();
        vector<int> ans(m*n,0);
        int i = 0;
        bool dir = true; // true-> up, false-> down;
        int x=0,y=0;
        while(i<m*n){
            ans[i] = mat[y][x];
            if(dir){
                if(y==0 && x!=n-1){
                    x++;
                    dir = false;
                }
                else if(x==n-1){
                    y++;
                    dir = false;
                }
                else{
                    x++;
                    y--;
                }
            }
            else{
                if(x==0 && y!=m-1){
                    y++;
                    dir = true;
                }
                else if(y==m-1){
                    x++;
                    dir = true;
                }
                else{
                    x--;
                    y++;
                }
            }
            i++;
        }
        return ans;
    }
};