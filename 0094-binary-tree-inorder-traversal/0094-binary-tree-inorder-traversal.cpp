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
//void solve(TreeNode* node){
    //if (node==nullptr){    // When node == nullptr, that recursive call returns to its parent, which resumes execution from where it paused and processes its remaining statements.
        //return;
    //}
    //solve(node->left);   // traverse left 
    //result.push_back(node->val);   // print the node
    //solve(node->right); // traverse the right 
//}
    vector<int> inorderTraversal(TreeNode* root) {
       //solve(root);
       //return result;
       vector<int> result;
       TreeNode* current=root;
       while(current!=nullptr){
            if (current->left==nullptr){
                result.push_back(current->val);
                current=current->right;
            }
            else {
                TreeNode* leftchild=current->left;
                while(leftchild->right != nullptr){
                    leftchild=leftchild->right;
                }
                leftchild->right=current;
                TreeNode * temp=current;
                current=current->left;
                temp->left=nullptr;
            }
       }
       return result;
    }
};