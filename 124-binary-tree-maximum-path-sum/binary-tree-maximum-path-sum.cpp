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
int maxo = INT_MIN, f=0;
    int solve(TreeNode* root, int flag){
        if(root==NULL)return 0;
        maxo=max(maxo,root->val);
        if((root->val) >= 0)f=1;
        int ans;
        if(flag){
            int l = max(0,solve(root->left,1));
            int r = max(0,solve(root->right,1));
            ans = max(0,max(l+root->val,r+root->val));
        }
        else{
            int l1 = max(0,solve(root->left,1));
            int r1 = max(0,solve(root->right,1));
            int l2 = max(0,solve(root->left,0));
            int r2 = max(0,solve(root->right,0));
            ans = max(0,max(l2,max(r2,root->val + l1 + r1)));
        }
        return ans;
    }
    int maxPathSum(TreeNode* root) {
        int ans = solve(root,0);
        return (f ? ans : maxo);
    }
};
