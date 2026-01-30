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
    TreeNode* solve(int i,int j, int a,int b,vector<int>& preorder, vector<int>& inorder){
        if(i>=preorder.size() || j<i || a>=preorder.size() || b<a)return NULL;
        TreeNode* root = new TreeNode(preorder[i]);
        // if(inorder[i]!=preorder[i]){
             
             for(int k=a;k<=b;k++){
                if(inorder[k]==preorder[i]){
                    root->left = solve(i+1,k-a+i,a,k-1,preorder,inorder);
                    root->right = solve(i+k-a+1,j,k+1,b,preorder,inorder);
                    break;
                }
             }
             return root;
        // }
    }
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        return solve(0,preorder.size()-1,0,preorder.size()-1,preorder,inorder);
    }
};