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

unordered_map<int,int>f;

int idx=0;

TreeNode* solve(vector<int>& preorder, vector<int>& inorder,int low,int high){

    if (low>high){
        return nullptr;
    }

    TreeNode* node=new TreeNode(preorder[idx]);
    idx++;
    int findindex=f[node->val];

    node->left=solve(preorder,inorder,low,findindex-1);
    node->right=solve(preorder,inorder,findindex+1,high);
    return node;
}

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {

        idx=0;
        f.clear();
        for (int i=0;i<inorder.size();i++){
            f[inorder[i]]=i;
        }
        return solve(preorder,inorder,0,inorder.size()-1);
    }
};