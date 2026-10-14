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
vector<int> result;
void solve(TreeNode* node){
    if (node==nullptr){
        return;
    }
    solve(node->left);   // traverse left 
    result.push_back(node->val);   // print the left 
    solve(node->right); // traverse the right 
    return;
}
    vector<int> inorderTraversal(TreeNode* root) {
        solve(root);
        return result;
    }
};