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

int maxsum=INT_MIN;

int solve(TreeNode* root){
    if (root==nullptr){
        return 0;
    }
    int left=solve(root->left);
    int right=solve(root->right);

    int maxleftorright=max(left,right) + root->val;
    int maxonlyroot = root->val;
    int maxleftandright = left + right + root->val;
    maxsum=max({maxsum,maxleftorright,maxonlyroot,maxleftandright});
    return max(maxleftorright,maxonlyroot);
}


    int maxPathSum(TreeNode* root) {
        //maxsum=INT_MIN;
        solve(root);
        return maxsum;
    }
};