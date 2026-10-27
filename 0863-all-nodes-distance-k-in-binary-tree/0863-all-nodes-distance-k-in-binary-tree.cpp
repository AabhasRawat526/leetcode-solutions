/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:

unordered_map<TreeNode* , TreeNode*> parent;

// parent ko construct kar diya now talking about BFS...

void constructparent(TreeNode* root){
    if (root==nullptr){
        return;
    }
    if (root->left != nullptr){
        parent[root->left]=root;
    }
    constructparent(root->left);
    if (root->right != nullptr){
        parent[root->right] = root;
    }
    constructparent(root->right);
}


void gettinganswer(TreeNode* target,int k,vector<int>& res){
    queue<TreeNode*>q;
    set<int>visited;
    q.push(target);
    visited.insert(target->val);

    while(!q.empty()){
        int n=q.size();
        
        if (k==0){
            break;
        }

        while(n--){
            TreeNode*t=q.front();
            q.pop();

            // FOR LEFT 

            if (t->left!=nullptr && visited.count(t->left->val)==0){
                q.push(t->left);
                visited.insert(t->left->val);
            }

            // FOR RIGHT

            if (t->right!=nullptr and visited.count(t->right->val)==0){
                q.push(t->right);
                visited.insert(t->right->val);
            }

            // FOR PARENT 

            if (parent.count(t) && visited.count(parent[t]->val)==0){
                q.push(parent[t]);
                visited.insert(parent[t]->val);
            }
        }
        k--;
    }

    while(!q.empty()){
        TreeNode* temp=q.front();
        q.pop();
        res.push_back(temp->val);
    }

}

    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        constructparent(root);
        vector<int>res;
        gettinganswer(target,k,res);
        return res;
    }
};