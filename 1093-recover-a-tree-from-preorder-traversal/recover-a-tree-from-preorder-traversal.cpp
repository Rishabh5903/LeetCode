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
    TreeNode* recoverFromPreorder(string s) {int n=s.size();
        stack<TreeNode*> st;int curr=0;TreeNode* ans=new TreeNode();st.push(ans);
        int i=0;
        while(i<n){
            string num="";
            while(i<n && s[i]=='-'){curr++;i++;}
            while(i<n && s[i]!='-'){num+=s[i];i++;}
            TreeNode* temp=new TreeNode(stoi(num));
            if(curr==0){st.top()->val=stoi(num);continue;}
            while(st.size()>curr)st.pop();
            if(!st.top()->left)st.top()->left=temp; else st.top()->right=temp;
            st.push(temp);
            curr=0;

        }
        return ans;
    }
};