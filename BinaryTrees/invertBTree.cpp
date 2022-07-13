#include<queue>
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
    TreeNode* invertTreeIter(TreeNode* root) {
        TreeNode* curr = root;
        TreeNode* temp;
        queue<TreeNode*> q;
        q.push(curr);
        while(q.size()!=0){
            if(curr!=nullptr){
                q.push(curr->left);
                q.push(curr->right);
                temp = curr->left;
                curr->left = curr->right;
                curr->right = temp;
            }
            q.pop();
            curr = q.front();
        }
        return root;
    }
    TreeNode* invertTreeRecur(TreeNode* root) {
        if (root == nullptr) {
            return nullptr;
        }

        TreeNode *left = root->left, *right = root->right;
        root->left = invertTreeRecur(right);
        root->right = invertTreeRecur(left);
        return root;
    }
};