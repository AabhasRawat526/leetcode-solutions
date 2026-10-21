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
    vector<int> rightSideView(TreeNode* root) {
        vector<int>res;
        if (root==nullptr){
            return res;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int levelscore=q.size();
            vector<int>temp;
            while(levelscore--){
                TreeNode* t=q.front();
                q.pop();
                temp.push_back(t->val);
                if (t->left!=nullptr){
                    q.push(t->left);
                }
                if (t->right!=nullptr){
                    q.push(t->right);
                }
            }
            res.push_back(temp.back());  // last node we are storing and the last node will always be right one node so that is why we are using the back one  .....
        }
        return res;
    }
};