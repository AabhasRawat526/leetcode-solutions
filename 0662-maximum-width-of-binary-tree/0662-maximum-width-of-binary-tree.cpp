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
    int widthOfBinaryTree(TreeNode* root) {
        int index=0;
        long long int maxwidth=0;
        if (root==nullptr){
            return 0;
        }
        queue<pair<TreeNode*,long long int>> q;
        q.push({root,index});
        while(!q.empty()){
            long long int left=q.front().second;
            long long int right=q.back().second;
            maxwidth=max(maxwidth,right-left+1);
            int levelscore=q.size();
            while(levelscore--){
                TreeNode* t=q.front().first;
                long long int idx=q.front().second-left;  // normalise...
                q.pop();
                if (t->left!=nullptr){
                    q.push({t->left,2*idx+1});
                }
                if (t->right!=nullptr){
                    q.push({t->right,2*idx+2});
                }
            }
        }
        return maxwidth;
    }
};

// idx - left changes the starting index, not the distance between nodes.

// Width= rightmost node index- leftmost node index+1

// Null values between the leftmost and rightmost actual nodes are counted, but null values after the rightmost actual node are not counted.