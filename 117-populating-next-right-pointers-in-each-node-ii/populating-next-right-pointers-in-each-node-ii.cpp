/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
        if(!root)return root;
        queue<Node*> q;
        q.push(root);
        Node* prev= new Node(); Node* curr=new Node();
        while(q.size()){
            int sz=q.size();
            prev=q.front();
            if(prev->left)q.push(prev->left);
            if(prev->right)q.push(prev->right);
            q.pop();
            for(int i=1;i<sz;i++){
                curr=q.front();
                if(curr->left)q.push(curr->left);
                if(curr->right)q.push(curr->right);
                q.pop();prev->next=curr;
                prev=curr;
            }

        }
        return root;
    }
};