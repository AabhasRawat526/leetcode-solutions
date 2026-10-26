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

map<int,int>mp;    // first one is the levelscore and the second one is the sum ...

void solve(TreeNode *root, int levelscore){
    if (root==nullptr){
        return;
    }
    mp[levelscore]+= root->val;
    solve(root->left,levelscore+1);
    solve(root->right,levelscore+1);
}

    int maxLevelSum(TreeNode* root) {
        /*
        BFS
        int maxsum=INT_MIN;    // TO HANDLE THE NEGATIVE SUM CASES 
        int result=0;
        int currentlevel=1;
        if (root==nullptr){
            return 0;
        }
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            int n=q.size();
            int sum=0;
            while(n--){
                TreeNode* t=q.front();
                q.pop();
                sum=sum+t->val;
                if (t->left!=nullptr){
                    q.push(t->left);
                }
                if (t->right!=nullptr){
                    q.push(t->right);
                }
            }
             if (sum > maxsum){
                maxsum=sum;
                result=currentlevel;
            }
            currentlevel++;
        }
        return result;
        */
        mp.clear();
        int maxsum=INT_MIN; // to handle the negative cases / sum cases 
        int result=0;
        solve(root,1);

        for (auto & id:mp){
            int sum=id.second;
            int res=id.first;
            if (sum>maxsum){
                maxsum=sum;
                result=res;
            }
        }
        return result;
    }
};