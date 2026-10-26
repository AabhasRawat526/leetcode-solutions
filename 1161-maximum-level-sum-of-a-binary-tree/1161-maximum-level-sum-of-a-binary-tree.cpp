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
    int maxLevelSum(TreeNode* root) {
        int maxsum=INT_MIN;    // TO HANDLE THE NEGATIVE SUM CASES 
        int result=0;
        int currentlevel=1;
        if (root==nullptr){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            while(n--){
                TreeNode* t=q.front();
                q.pop();
                sum=sum+t->val;
                if (t->left!=nullptr){
                    q.push(t->left);
                }
                if (t->right!=nullptr){
                    q.push(t->right);
                }
            }
             if (sum > maxsum){
                maxsum=sum;
                result=currentlevel;
            }
            currentlevel++;
        }
        return result;
    }
};