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

int wrong=0;

TreeNode* previous=nullptr;
TreeNode* wrong1first=nullptr;
TreeNode* wrong1second=nullptr;
TreeNode* wrong2first=nullptr;
TreeNode* wrong2second=nullptr;

void solve(TreeNode* root){
    if (root==nullptr){
        return;
    }
    solve(root->left);
    if (previous==nullptr){
        previous=root;
    }
    else {
        if (root->val < previous->val){
            if (wrong==0){
                wrong1first=root;
                wrong1second=previous;
                wrong++;
            }
            else {
                wrong2first=root;
                wrong2second=previous;
                wrong++;
            }
        }
        previous=root;
    }
    solve(root->right);
}

    void recoverTree(TreeNode* root) {
        solve(root);
        if (wrong==1){
            swap(wrong1first->val,wrong1second->val);
        }
        else {
            swap(wrong1second->val,wrong2first->val);
        }
    }
};