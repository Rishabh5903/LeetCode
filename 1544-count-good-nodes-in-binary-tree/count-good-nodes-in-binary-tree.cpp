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
    int ans;
    void isgood(TreeNode* root, int maxo){
        if(!root)return ;
        if(root->val >= maxo)ans++;
        maxo = max(maxo, root->val);
        isgood(root->left, maxo);
        isgood(root->right, maxo);

    }
    int goodNodes(TreeNode* root) {
        ans=0;
        isgood(root, -10001);
        return ans;
    }
};