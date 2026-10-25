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

int sum=0;
long long int maxP=0;
int MOD=1e9 + 7;

int totalsum(TreeNode* root){
    if (root==nullptr){
        return 0;
    }
    int leftsum=totalsum(root->left);
    int rightsum=totalsum(root->right);
    sum=root->val + leftsum + rightsum;
    return sum;
}

int subtreesum(TreeNode * root){
    if (root==nullptr){
        return 0;
    }
    int leftsubtree=subtreesum(root->left);
    int rightsubtree=subtreesum(root->right);
    long long int minisum= root->val + leftsubtree + rightsubtree;
    long long int remainingsum=sum-minisum;
    maxP=max(maxP,minisum*remainingsum);
    return minisum;
}

    int maxProduct(TreeNode* root) {
        if (root==nullptr){
            return 0;
        }

        totalsum(root);

        subtreesum(root);

        return (maxP) % MOD;
    }
};