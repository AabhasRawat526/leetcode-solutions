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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> res;
        int lefttoright=1;
        if (root==nullptr){
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelorder=q.size();
            int first=0;
            int last=levelorder-1;
            vector<int>temp(levelorder);
            while(levelorder--){
                TreeNode* t=q.front();
                q.pop();
                if (lefttoright==1){
                    temp[first]=t->val;
                    first++;
                }
                else {
                    temp[last]=t->val;
                    last--;
                }
                if (t->left!=nullptr){
                    q.push(t->left);
                }
                if (t->right!=nullptr){
                    q.push(t->right);
                }
            }
            res.push_back(temp);
            lefttoright=1-lefttoright;
        }
        return res;
    }
};