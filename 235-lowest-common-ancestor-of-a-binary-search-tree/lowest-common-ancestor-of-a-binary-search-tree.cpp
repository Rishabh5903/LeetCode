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
void dfs(TreeNode* i, TreeNode* root, vector<TreeNode*>& v){
    v.push_back(root);
    if(root->val == i->val){
        
        return;
    }
    if(root->val > i->val)dfs(i,root->left,v);
    else dfs(i, root->right, v);
}
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
        vector<TreeNode*> v1,v2;
        dfs(p, root, v1);
        dfs(q, root, v2);
        TreeNode* ans;
        for(int i=0;i<min(v1.size(),v2.size());i++){
            if(v1[i] == v2[i])ans=v1[i];
            else break;
        }
        return ans;

    }
};