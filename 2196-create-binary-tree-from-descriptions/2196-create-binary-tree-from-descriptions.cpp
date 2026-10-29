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
    TreeNode* createBinaryTree(vector<vector<int>>& descriptions) {
        unordered_map<int,TreeNode*>mp;
        unordered_set<int>visited;
        for (vector<int>& vec: descriptions){
            int parent=vec[0];
            int child=vec[1];
            int isleft=vec[2];
            if (mp.find(parent)==mp.end()){
                mp[parent]=new TreeNode(parent);
            }
            if (mp.find(child)==mp.end()){
                mp[child]=new TreeNode(child);
            }
            if (isleft==1){
                mp[parent]->left=mp[child];
            }
            else {
                mp[parent]->right=mp[child];
            }
            visited.insert(child);
        }
        for (vector<int>& vec1:descriptions){
            int parent1=vec1[0];
            if (visited.find(parent1)==visited.end()){
                return mp[parent1];
            }
        }
        return nullptr;
    }
};