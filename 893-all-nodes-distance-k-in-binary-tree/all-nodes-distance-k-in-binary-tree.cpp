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
    vector<vector<int>> g;
    void dfs(TreeNode* root){
        if(root==NULL) return;
        if(root->left){
                g[root->val].push_back(root->left->val);
                g[root->left->val].push_back(root->val);
                dfs(root->left);
                }
        if(root->right){
                g[root->val].push_back(root->right->val);
                g[root->right->val].push_back(root->val);
                dfs(root->right);
                }
    }
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        g.resize(501);
        vector<int> ans;
        dfs(root);
        queue<int> q;
        q.push(target->val);
        // return g[2];
        vector<int> vis(501);
        vis[q.front()] = 1;
        while(k){
            int sz=q.size();
            for(int i=0;i<sz;i++){
                int u = q.front(); q.pop();
                for(int v:g[u])if(!vis[v]){q.push(v); vis[v]=1;}
            }
            k--;
        }
        while(q.size()){
            ans.push_back(q.front());
            q.pop();
        }
        return ans;
            


    }
};