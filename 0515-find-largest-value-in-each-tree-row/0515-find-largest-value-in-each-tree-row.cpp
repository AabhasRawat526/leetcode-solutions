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
    vector<int> largestValues(TreeNode* root) {
        vector<int>res;
        if (root==nullptr){
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int temp=INT_MIN;
            while(n--){
                TreeNode* t=q.front();
                temp=max(temp,t->val);
                q.pop();
                if (t->left!=nullptr){
                    q.push(t->left);
                }
                if (t->right!=nullptr){
                    q.push(t->right);
                }
            }
            res.push_back(temp);
        }
        return res;
    }
};