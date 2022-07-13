#include<vector>
using namespace std;
class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        vector<vector<bool>> visited(m,vector<bool>(n,false));
        vector<int> ans;
        int x=0, y=0, dir=0;
        int dr[] = {0,1,0,-1};
        int dc[] = {1,0,-1,0};
        for(int i=0; i<m*n; i++){
            ans.push_back(matrix[x][y]);
            visited[x][y]=true;
            int newX = x + dr[dir];
            int newY = y + dc[dir];
            if (0 <= newX && newX < m && 0 <= newY && newY < n && !visited[newX][newY]) {
                x = newX;
                y = newY;
            }
            else {
                dir = (dir + 1) % 4;
                x += dr[dir];
                y += dc[dir];
            }
        }
        return ans;
    }
};