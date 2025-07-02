class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        set<int> s1,s2;
        int ans=edges.size();
        for(int i=0;i<edges.size();i++){
            if(node1>=0)s1.insert(node1);
            if(node2>=0)s2.insert(node2);
            if(node1>=0 && s2.find(node1)!=s2.end())ans=min(ans,node1);
            if(node2>=0 && s1.find(node2)!=s1.end())ans=min(ans,node2);
            if(ans<edges.size())return ans;
            if(node2>=0)node2=edges[node2];
            if(node1>=0)node1=edges[node1];
        }
        return -1;
    }
};