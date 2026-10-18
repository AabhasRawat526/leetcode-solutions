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

string solve(TreeNode* root,vector<TreeNode*> & res,unordered_map<string,int> & f){
    if (root==nullptr){
        return "N";
    }
    string s=to_string(root->val) + "," + solve(root->left,res,f) + "," + solve(root->right,res,f);
    if (f[s]==1){
        res.push_back(root);
    }
    f[s]++;
    return s;
}

    vector<TreeNode*> findDuplicateSubtrees(TreeNode* root) {
        vector<TreeNode*> res;
        unordered_map<string,int> f;
        solve(root,res,f);
        return res;
    }
};