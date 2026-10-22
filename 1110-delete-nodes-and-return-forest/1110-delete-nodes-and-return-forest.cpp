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

TreeNode* solve(TreeNode* root,vector<int>& to_delete,unordered_set<int> & st,vector <TreeNode*> & result){
    if (root==nullptr){
        return nullptr;
    }
    root->left=solve(root->left,to_delete,st,result);
    root->right=solve(root->right,to_delete,st,result);
    if (st.find(root->val)!=st.end()){
        if (root->left!=nullptr){
            result.push_back(root->left);
        }
        if (root->right!=nullptr){
            result.push_back(root->right);
        }
        return nullptr;
    }
    else {
        return root;
    }
}

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int>st;
        for (int &nums:to_delete){
            st.insert(nums);
        }
        solve(root,to_delete,st,result);
        if (st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
    }
};