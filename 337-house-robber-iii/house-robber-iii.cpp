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
    unordered_map<TreeNode*, unordered_map<int, int>> dp;
    int solve(TreeNode* root, int take){
        if(root == NULL) return dp[root][take] = 0;
        if(dp.count(root) && dp[root].count(take)) return dp[root][take];
        if(take){
            return dp[root][take] = max(root->val + solve(root->left, 0) + solve(root->right, 0), solve(root->left, 1) + solve(root->right, 1));
        }
        return dp[root][take] = solve(root->left, 1) + solve(root->right, 1);
    }
    int rob(TreeNode* root) {
        
        return solve(root,1);
    }
};