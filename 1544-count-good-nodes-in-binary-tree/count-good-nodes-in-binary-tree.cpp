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
    void count(TreeNode* root, int par, int& ans){
        if(!root)return;
        if(root->val >=par)ans++;
        count(root->left, max(par,root->val), ans);
        count(root->right, max(par,root->val), ans);
    }
    int goodNodes(TreeNode* root) {
        int ans=0;
        count(root,-1e4-1,ans);
        return ans;
    }
};