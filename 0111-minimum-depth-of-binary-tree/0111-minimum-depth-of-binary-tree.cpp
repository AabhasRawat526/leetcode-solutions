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
    int minDepth(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }
        queue<TreeNode*> q;
        q.push(root);
        int depth=1;
        while(!q.empty()){
            int levelscore=q.size();
            while(levelscore--){
                TreeNode* t=q.front();
                q.pop();
                if (t->left==nullptr && t->right==nullptr){
                    return depth;
                }
                if (t->left!=nullptr){
                    q.push(t->left);
                }
                if (t->right!=nullptr){
                    q.push(t->right);
                }
            }
            depth++;
        }
        return -1;
    }
};