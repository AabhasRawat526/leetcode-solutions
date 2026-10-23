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

TreeNode* solve(TreeNode* root,int val){
    if (root==nullptr){
        return 0;    // 0 and nullptr is same in the TreeNode 
    }
    if (root->val == val){
        return root;
    }
    else if (root->val > val){
        return solve(root->left,val);
    }
    else {
        return solve(root->right,val);
    }
};

    TreeNode* searchBST(TreeNode* root, int val) {
        return solve(root,val);
    }
};

// solve(root->left, val); — call the next function, but don't forward its result.

//return solve(root->left, val); — call the next function and forward its result to whoever called you.