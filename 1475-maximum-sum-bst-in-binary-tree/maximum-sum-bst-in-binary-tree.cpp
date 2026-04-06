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
unordered_map<TreeNode*, vector<int>> mp;
unordered_map<TreeNode*, bool> isbst;
    bool isBST(TreeNode* root){
        if(isbst.count(root))return isbst[root];
        if(root == NULL) return isbst[root]=true;
        if(root->left){
            if(!isBST(root->left) || (mp[root->left][2] >= root->val))return isbst[root]=false;
        }
        if(root->right){
            if(!isBST(root->right) || (mp[root->right][1] <= root->val)) return isbst[root]=false;
        }
        return isbst[root]=true;
    }
    vector<int> precompute(TreeNode* root){
        if(mp.count(root))return mp[root];
        if(!root)return mp[root]={0,INT_MAX,INT_MIN};
        return mp[root]={(root->val + precompute(root->left)[0] + precompute(root->right)[0]), min(root->val, min(precompute(root->left)[1], precompute(root->right)[1])), max(root->val, max(precompute(root->left)[2], precompute(root->right)[2]))};
    }

    void solve(TreeNode* root, int& ans){
        if(root == NULL) return;
        if(isBST(root)){
            ans=max(ans, mp[root][0]);
        }
        solve(root->left, ans);
        solve(root->right, ans);
    }
    int maxSumBST(TreeNode* root) {
        precompute(root);
        int ans=INT_MIN;
        solve(root, ans);
        return max(0,ans);
    }
};