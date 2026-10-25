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

int findmaxdiff(TreeNode* root, int maxval,int minval){
    if (root==nullptr){
        return abs(maxval-minval);
    }
    maxval=max(maxval,root->val);
    minval=min(minval,root->val);
    int left=findmaxdiff(root->left,maxval,minval);
    int right=findmaxdiff(root->right,maxval,minval);
    return max(left,right);
}

    int maxAncestorDiff(TreeNode* root) {
        return findmaxdiff(root,root->val,root->val);
    }
};