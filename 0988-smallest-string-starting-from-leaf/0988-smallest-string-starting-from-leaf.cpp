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

string result;
void solve(TreeNode* root,string current){
    if (root==nullptr){
        return;
    }
    current=char(root->val + 'a') + current;     // add the character at the starting 

    if (root->left==nullptr && root->right==nullptr){
        if (result=="" || result>current){
            result=current;
        }
    }
    solve(root->left,current);
    solve(root->right,current);
}

    string smallestFromLeaf(TreeNode* root) {
        solve(root,"");
        return result;
    }
};