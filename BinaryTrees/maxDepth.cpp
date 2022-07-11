#include<bits/stdc++.h>
using namespace std;

//Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode() : val(0), left(nullptr), right(nullptr) {}
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
    TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

class Solution {
public:
    // Recursive Solution:
    int maxDepthRecur(TreeNode* root) {
        if(root==nullptr) return 0;
        int l = maxDepth(root->left);
        int r = maxDepth(root->right);
        if(l>r) return l+1;
        else    return r+1;
    }
    // Iterative Solution:
    int maxDepthIter(TreeNode* root) {
        if(!root) return 0;
        queue<TreeNode*> q;
        TreeNode* curr = root;
        q.push(curr);
        int depth=0;
        int lvlCnt = 1;
        while(q.size()!=0){
            for(int i=0; i<lvlCnt; i++){
                curr = q.front();
                q.pop();
                if(curr->left!=nullptr){
                    q.push(curr->left);
                }
                if(curr->right!=nullptr){
                    q.push(curr->right);
                }
            }
            lvlCnt = q.size();
            depth++;
        }
        return depth;
    }
};