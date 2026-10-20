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

bool solve(TreeNode* root){
    bool isnull=false;
    if (root==nullptr){
        return true;
    }
    queue<TreeNode*>q;
    q.push(root);
    while(!q.empty()){
        TreeNode* t=q.front();
        q.pop();
        if (t==nullptr){
            isnull=true;
        }
        else {
            if (isnull){
                return false;
            }
            q.push(t->left);
            q.push(t->right);
        }
    }
    return true;
}

    bool isCompleteTree(TreeNode* root) {
        return solve(root);
    }
};