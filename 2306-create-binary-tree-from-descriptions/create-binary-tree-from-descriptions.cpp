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
void dfs(map<int,vector<pair<int,int>>>& mp,TreeNode* temp){
    if(!mp[temp->val].size())return;
    for(auto i:mp[temp->val]){
        TreeNode* t=new TreeNode();t->val=i.first;
        if(i.second==0)temp->right=t;
        else temp->left=t;
        dfs(mp,t);
    }
}
    TreeNode* createBinaryTree(vector<vector<int>>& d) {
       map<int,vector<pair<int,int>>> mp;
        unordered_map<int,int> par;
        for(auto i:d){
            mp[i[0]].push_back({i[1],i[2]});par[i[1]]=i[0];
        }
        TreeNode* root=new TreeNode();
        for(auto i:d){
            if(!par[i[0]]){root->val=i[0];break;}
            if(!par[i[1]]){root->val=i[1];break;}
        }
        TreeNode* temp=root;
        dfs(mp,temp);
        return root;
    }
};