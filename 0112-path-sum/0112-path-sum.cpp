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


bool res=false;

void solve(TreeNode* root,int sum,int targetSum){
    if (root==nullptr){
        return;
    }
    sum=sum+root->val;
    if (root->left==nullptr and root->right==nullptr){
        if (sum==targetSum){
            res=true;
            return;
        }
    }
    else {
        solve(root->left,sum,targetSum);
        solve(root->right,sum,targetSum);
    }
}

    bool hasPathSum(TreeNode* root, int targetSum) {
        solve(root,0,targetSum);
        return res;
    }
};