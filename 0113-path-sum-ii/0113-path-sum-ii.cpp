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

vector<vector<int>>res;

void solve(TreeNode* root,int sum,vector<int> &temp,int targetSum){
    if (root==nullptr){
        return;
    }
    sum=sum+root->val;
    temp.push_back(root->val);
    if (root->left==nullptr and root->right==nullptr){
        if (sum==targetSum){
            res.push_back(temp);
            temp.pop_back();   // 
            return;
        }
    }
    solve(root->left,sum,temp,targetSum);
    solve(root->right,sum,temp,targetSum);
    temp.pop_back();
    return;

}


    vector<vector<int>> pathSum(TreeNode* root, int targetSum) {
        vector<int> temp;
        solve(root,0,temp,targetSum);
        return res;
    }
};