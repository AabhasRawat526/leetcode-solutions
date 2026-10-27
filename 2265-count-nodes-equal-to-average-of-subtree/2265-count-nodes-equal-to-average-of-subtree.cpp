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

int result=0;

pair<int,int> solve(TreeNode* root){      // first int is for sum and the second int is for the count
    if (root==nullptr){
        return {0,0};
    }

    auto p1=solve(root->left);
    auto p2=solve(root->right);

    auto calculatesum=p1.first+p2.first+root->val;

    auto calculatecount=p1.second+p2.second+1;

    int avg=(calculatesum)/calculatecount;

    if (avg==root->val){
        result++;
    }
    return {calculatesum,calculatecount};

}

    int averageOfSubtree(TreeNode* root) {
        solve(root);
        return result;    
    }
};