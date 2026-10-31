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

// tc is 0(n)
// but using 0(2n) as because we are first finding the maxdepth then finding the lca causing the 0(2n)
class Solution {
public:

int maxdepth=0;

unordered_map<int,int>mp;

void finddeepestlevel(TreeNode* root,int depth){
    if (root==nullptr){
        return;
    }
    //mp[root->val]=depth;
    maxdepth=max(maxdepth,depth);
    mp[root->val]=depth;
    finddeepestlevel(root->left,depth+1);
    finddeepestlevel(root->right,depth+1);
}

TreeNode*lcafindofdeepestlevel(TreeNode* root){
    if (root==nullptr){
        return nullptr;
    }

    if (mp[root->val]==maxdepth){
        return root;
    }

    TreeNode* left=lcafindofdeepestlevel(root->left);
    TreeNode* right=lcafindofdeepestlevel(root->right);

    if (left!=nullptr and right!=nullptr){
        return root;
    }
    if (left!=nullptr){
        return left;
    }
    return right;
}

    TreeNode* lcaDeepestLeaves(TreeNode* root) {
        finddeepestlevel(root,0);
        return lcafindofdeepestlevel(root);
    }
};