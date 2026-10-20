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

int res=0;

int solve(TreeNode * root){
    if (root==nullptr){
        return 0;
    }
    int left=solve(root->left);
    int right=solve(root->right);
    int sum=left+right;
    res=max(res,sum);
    return 1  + max(left,right);
}

    int diameterOfBinaryTree(TreeNode* root) {
        solve(root);
        return res;
    }
};

// res → Stores the maximum diameter found in the entire binary tree.

//return 1 + max(left, right) → Returns the height of the current subtree to its parent, so the parent can calculate its own diameter.

// needs to know the height of its left subtree to calculate the diameter passing through node..