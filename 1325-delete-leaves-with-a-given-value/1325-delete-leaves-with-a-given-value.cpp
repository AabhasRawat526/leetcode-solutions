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

TreeNode* solve(TreeNode* root,int target){
    if (root==nullptr){
        return nullptr;
    }
    root->left=solve(root->left,target);    // storing the what root->left will point to or what root->left should be like it should connected to that number other then target or if the root->left is the target so it should be disconnected and return nullptr...
    root->right=solve(root->right,target);   // storing the what root->left will point to or what root->left should be like it should connected to that number other then target or if the root->left is the target so it should be disconnected and return nullptr...
    if (root->left==nullptr and root->right==nullptr){
        if (root->val==target){
            return nullptr;
        }
    }
    return root;
}

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        return solve(root,target);
    }
};

// tc is 0(n)
// sc is 0(height of tree)
// sc is 0(n) skew tree 