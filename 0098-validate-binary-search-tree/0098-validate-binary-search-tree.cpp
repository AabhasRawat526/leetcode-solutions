/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:

bool ans=true;

TreeNode* previous=nullptr;

void solve(TreeNode* root){
    if (root==nullptr){
        return;
    }
    solve(root->left);
    if (previous==nullptr){
        previous=root;
    }
    else {
        if (root->val <= previous->val){
            ans=false;
        }
        previous=root;
    }
    solve(root->right);
}

    bool isValidBST(TreeNode* root) {
        solve(root);
        return ans;
    }
};