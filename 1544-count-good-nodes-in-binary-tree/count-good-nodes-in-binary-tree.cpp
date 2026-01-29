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
    void traverse(TreeNode* node, int v, int& cnt)
    {
        if(node == nullptr) return;
        if(node->val >= v)
        {
            v = node->val; 
            ++cnt;
        }

        traverse(node->left, v, cnt);
        traverse(node->right, v, cnt);
        
    }

    int goodNodes(TreeNode* root) 
    {
        int cnt = 0;
        traverse(root, root->val, cnt);
        return cnt;
    }
};