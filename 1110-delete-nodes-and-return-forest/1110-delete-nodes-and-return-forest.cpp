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

TreeNode* solve(TreeNode* root,vector<int>& to_delete,unordered_set<int> & st,vector <TreeNode*> & result){
    if (root==nullptr){
        return nullptr;
    }
    root->left=solve(root->left,to_delete,st,result);
    root->right=solve(root->right,to_delete,st,result);
    if (st.find(root->val)!=st.end()){
        if (root->left!=nullptr){
            result.push_back(root->left);
        }
        if (root->right!=nullptr){
            result.push_back(root->right);
        }
        return nullptr;   // disconnects the children node with the parent node 
    }
    else {
        return root;    // keep the children node connected with the parent node 
    }
}

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        vector<TreeNode*> result;
        unordered_set<int>st;
        for (int &nums:to_delete){
            st.insert(nums);
        }
        solve(root,to_delete,st,result);
        if (st.find(root->val)==st.end()){
            result.push_back(root);
        }
        return result;
    }
};

// If the node is NOT deleted: return root; — return the node so it stays connected to its parent, along with its subtree.

//If the node IS deleted: return nullptr; — disconnect it from its parent. Its surviving children can become separate tree roots, so we add them to result.

/*

Input: root = [1,2,3,4,5,6,7], to_delete = [3,5]

when 5 delete it does return nullptr means it is disconnected 

Since node 5 returns nullptr, this becomes:
root->right = nullptr;

means 2 right is nullptr 

Now node 2 has no right child. The nullptr is stored in the tree's right pointer, not in result.

when 3 is deleted so in result 6 and 7 is added then return nullptr means 1 right side is assign to nullptr 

so final answer is [[1,2,null,4],[6],[7]]

Exactly, [1,2,null,4] represents the entire tree rooted at node 1, including all its connected nodes and missing-child positions.

If you additionally include [1,null] as another tree, it would represent another tree with node 1 as its root, which is incorrect because we haven't created another node with value 1.
*/