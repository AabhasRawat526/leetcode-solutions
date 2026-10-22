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

void solve1(TreeNode* root1,string & s1){
    if (root1==nullptr){
        return;
    }

    if (root1->left==nullptr and root1->right==nullptr){
        s1+=to_string(root1->val)+ "_";
    }
    else {
        solve1(root1->left,s1);
        solve1(root1->right,s1);
    }
}

void solve2(TreeNode* root2,string & s2){
    if (root2==nullptr){
        return;
    }

    if (root2->left==nullptr && root2->right==nullptr){
        s2=s2+to_string(root2->val)+ "_";
    }
    else {
        solve2(root2->left,s2);
        solve2(root2->right,s2);
    }
}

    bool leafSimilar(TreeNode* root1, TreeNode* root2) {
        string s1="";
        string s2="";
        solve1(root1,s1);
        solve2(root2,s2);
        return (s1==s2);
    }
};