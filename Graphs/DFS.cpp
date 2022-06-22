#include<bits/stdc++.h>
using namespace std;
class Solution {
    public:
    vector<int> dfsOfGraph(int V, vector<int> adj[]) {
        vector<bool> visited(V,false);
        visited[0]=true;
        vector<int> dfs;
        int cur=0,j;
        stack<int> s;
        s.push(cur);
        while(s.size()!=0){
            if(visited[cur]){
                for(int i = adj[cur].size()-1; i >= 0; i--){
                    j = adj[cur][i];
                    if(!visited[j]){
                        s.push(j);
                    }
                }
                dfs.push_back(cur);
                cur=s.top();
                if(visited[cur]){
                    break;
                }
                else{
                    visited[cur]=true;
                }
                s.pop();
            }
        }
        return dfs;
    }
};