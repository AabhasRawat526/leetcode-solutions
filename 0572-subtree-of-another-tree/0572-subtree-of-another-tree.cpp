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

bool solve(TreeNode* root, TreeNode* subRoot){
    if (root==nullptr and subRoot==nullptr){
        return true;
    }
    if (root==nullptr or subRoot==nullptr){
        return false;
    }
    if (root->val !=subRoot->val){
        return false;
    }
    bool r1=solve(root->left,subRoot->left);
    bool r2=solve(root->right,subRoot->right);
    if (r1==true and r2==true){
        return true;
    }
    return false;
}

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if (root==nullptr){
            return false;
        }
        if (solve(root,subRoot)){
            return true;
        }
        return isSubtree(root->left,subRoot) || isSubtree(root->right,subRoot);
    }
};


// when 3 compares with 4 3 == 4 return false still not false because solve function gives me false answer not the subTree function subTree function ask to check the left of the root and the right of the root with the subroot after checking if the values do not matches then bothe return false then the final answer is false if one is false so it goes to the another function to check for it if both true then only the answer will be true ......