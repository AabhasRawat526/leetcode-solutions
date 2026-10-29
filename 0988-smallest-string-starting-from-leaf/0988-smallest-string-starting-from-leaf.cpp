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

// DFS CODE 

//string result;
//void solve(TreeNode* root,string current){     // string current in this i passes by value as it creates it own copy ......
    //if (root==nullptr){
        //return;
    //}
    //current=char(root->val + 'a') + current;     // add the character at the starting tc is 0(length of the current)

    //if (root->left==nullptr && root->right==nullptr){
        //if (result=="" || result>current){
            //result=current;
        //}
    //}
    //solve(root->left,current);
    //solve(root->right,current);
//}

    string smallestFromLeaf(TreeNode* root) {
        //solve(root,"");
        //return result;
        // BFS CODE

        string res="";
        if (root==nullptr){
            return res;
        }
        queue<pair<TreeNode *,string>>q;
        q.push({root,string(1,char(root->val + 'a'))});
        while(!q.empty()){
            auto[node,current]=q.front();
            q.pop();
            if (node->left==nullptr && node->right==nullptr){
                if (res=="" || res > current){
                    res=current;
                }
            }
            if (node->left!=nullptr){
                q.push({node->left,char(node->left->val + 'a')+current});
            }
            if (node->right!=nullptr){
                q.push({node->right,char(node->right->val + 'a')+current});
            }
        }
        return res;
    }
};