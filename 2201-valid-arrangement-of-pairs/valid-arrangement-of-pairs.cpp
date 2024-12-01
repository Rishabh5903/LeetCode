class Solution {
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        unordered_map<int,list<int>> graph;
        unordered_map<int,int> deg;
        for(auto& pair:pairs){
            int u=pair[0],v=pair[1];
            graph[u].push_back(v);
            deg[u]++;deg[v]--;
        }

        int start=pairs[0][0];
        for(auto& [node,degree]:deg){
            if(degree==1){start=node;break;}
        }
        vector<vector<int>> ans;
        function<void(int)> dfs = [&](int node){
            auto& neighbours=graph[node];
            while(!neighbours.empty()){
                int next=neighbours.front();neighbours.pop_front();
                dfs(next);
                ans.push_back({node,next});
            }
        };
        dfs(start);
        reverse(ans.begin(),ans.end());
        return ans;
    }
};