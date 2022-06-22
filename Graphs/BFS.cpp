#include<bits/stdc++.h>
using namespace std;
class Solution {
public:
    vector<int> bfsOfGraph(int V, vector<int> adj[]) {
        queue<int> q;
        vector<bool> visited(V,false);
        visited[0]=true;
        vector<int> bfs;
        int cur=0;
        q.push(cur);
        while(q.size()!=0){
            if(visited[cur]){
                for(int j: adj[cur]){
                    if(!visited[j]){
                        q.push(j);
                        visited[j]=true;
                    }
                }
                bfs.push_back(cur);
                q.pop();
                cur = q.front();
            }
        }
        return bfs;
    }
};