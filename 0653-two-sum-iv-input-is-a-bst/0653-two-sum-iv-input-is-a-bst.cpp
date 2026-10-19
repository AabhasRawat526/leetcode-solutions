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

stack<TreeNode*> asc;
stack<TreeNode* > des;

int getascdata(){
    TreeNode* small=asc.top();
    asc.pop();
    TreeNode*rightside=small->right;
    while(rightside!=nullptr){
        asc.push(rightside);
        rightside=rightside->left;
    }
    return small->val;
}

int getdesdata(){
    TreeNode* big=des.top();
    des.pop();
    TreeNode* leftside=big->left;
    while(leftside!=nullptr){
        des.push(leftside);
        leftside=leftside->right;
    }
    return big->val;
}

    bool findTarget(TreeNode* root, int k) {
        TreeNode* t=root;
        while(t){
            asc.push(t);
            t=t->left;
        }
        t=root;
        while(t){
            des.push(t);
            t=t->right;
        }
        int x=getascdata();
        int y=getdesdata();
        while(x<y){
            if (x+y==k){
                return true;
            }
            else if (x+y < k){
                x=getascdata();
            }
            else {
                y=getdesdata();
            }
        }
        return false;
    }
};