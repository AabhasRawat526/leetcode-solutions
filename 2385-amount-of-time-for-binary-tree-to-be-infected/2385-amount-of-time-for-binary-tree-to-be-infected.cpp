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

void undirectedgraph(unordered_map<int,vector<int>>& mp,int parent,TreeNode * root){
    if (root==nullptr){
        return;
    }
    if (parent!=-1){
        mp[root->val].push_back(parent);
    }
    if (root->left!=nullptr){
        mp[root->val].push_back(root->left->val);
    }
    if (root->right!=nullptr){
        mp[root->val].push_back(root->right->val);
    }
    undirectedgraph(mp,root->val,root->left);
    undirectedgraph(mp,root->val,root->right);
}

    int amountOfTime(TreeNode* root, int start) {
        unordered_map<int,vector<int>>mp;
        set<int>visited;
        undirectedgraph(mp,-1,root);

        int totalminutes=0;
        
        if (root==nullptr){
            return 0;
        }
        queue<int>q;
        q.push(start);
        visited.insert(start);

        while(!q.empty()){
            int n=q.size();

            while(n--){
                int t=q.front();
                q.pop();
                for (int affected:mp[t]){
                    if(visited.find(affected)==visited.end()){
                        q.push(affected);
                        visited.insert(affected);
                    }
                }
            }
            totalminutes++;
        }
        return (totalminutes-1);
    }
};