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

// LCA FINDING 

TreeNode* ans=nullptr;


int solve(TreeNode* root,int startValue,int destValue){
    if (root==nullptr){
        return 0;
    }
    int left=solve(root->left,startValue,destValue);
    int right=solve(root->right,startValue,destValue);
    int self=0;
    if (root->val==startValue || root->val==destValue){
        self=1;
    }
    int total=0;
    total=left+right+self;
    if (total==2 and ans==nullptr){
        ans=root;
    }
    return total;
}


// PATH EXPLORATION 

bool directionfind(TreeNode* ans,int target,string& path){
    if (ans==nullptr){
        return false;
    }
    if (ans->val==target){
        return true;
    }

    // EXPLORING LEFT
    path.push_back('L');
    if (directionfind(ans->left,target,path)==true){
        return true;
    }
    path.pop_back();


    // EXPLORING THE RIGHT PATH
    path.push_back('R');
    if (directionfind(ans->right,target,path)==true){
        return true;
    }
    path.pop_back();

    return false;
}

    string getDirections(TreeNode* root, int startValue, int destValue) {
        solve(root,startValue,destValue);
        string lcatosrc="";
        string lcatodes="";
        directionfind(ans,startValue,lcatosrc);
        directionfind(ans,destValue,lcatodes);
        string result="";
        for (int i=0;i<lcatosrc.size();i++){
            result.push_back('U');
        }
        result=result+lcatodes;
        return result;
    }
};