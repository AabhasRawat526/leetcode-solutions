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
    TreeNode* addOneRow(TreeNode* root, int val, int depth) {
        if (root==nullptr){
            return nullptr;
        }
        if (depth==1){
            TreeNode* newroot=new TreeNode(val);
            newroot->left=root;
            return newroot;
        }
        queue<TreeNode*>q;
        q.push(root);
        int leveldepth=1;
        while(!q.empty()){
            int levelscore=q.size();
            while(levelscore--){
                TreeNode* t=q.front();
                TreeNode* oldleft=t->left;
                TreeNode* oldright=t->right;
                q.pop();
                if (leveldepth==depth-1){
                    t->left=new TreeNode(val);
                    t->right=new TreeNode(val);
                    t->left->left=oldleft;
                    t->right->right=oldright;
                }
                else {
                    if (t->left!=nullptr){
                        q.push(t->left);
                    }
                    if (t->right!=nullptr){
                        q.push(t->right);
                    }
                }
            }
            leveldepth++;
        }
        return root;
    }
};