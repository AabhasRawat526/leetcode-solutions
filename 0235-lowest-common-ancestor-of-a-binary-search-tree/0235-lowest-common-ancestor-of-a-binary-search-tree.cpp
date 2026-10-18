/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */

class Solution {
public:

TreeNode* ans=nullptr;

void solve(TreeNode* root,TreeNode* p,TreeNode* q){
    if (root==nullptr){
        return;
    }
    if (root==p or root==q){
        ans=root;
        return;
    }
    if (root->val > p->val && root->val > q->val){
        solve(root->left,p,q);
    }
    else if (root->val < p->val && root->val < q->val){
        solve(root->right,p,q);
    }
    else {
        ans=root;
        return;
    }
}

    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        solve(root,p,q);
        return ans;
    }
};