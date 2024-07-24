/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};
*/

class Solution {
public:
    Node* dfs(Node* node, map<Node*, Node*>& vis) {
        if (!node) return nullptr;
        if (vis.find(node) != vis.end()) return vis[node];
        
        Node* clone = new Node(node->val);
        vis[node] = clone;
        
        for (auto neighbor : node->neighbors) {
            clone->neighbors.push_back(dfs(neighbor, vis));
        }
        
        return clone;
    }
    
    Node* cloneGraph(Node* node) {
        map<Node*, Node*> vis;
        return dfs(node, vis);
    }
};