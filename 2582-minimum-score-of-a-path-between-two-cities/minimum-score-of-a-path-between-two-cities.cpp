class Solution {
public:
    void dfs(int i, vector<vector<pair<int,int>>>& g, vector<int>& vis, int& ans){
        if(vis[i])return;
        vis[i]=1;
        for(auto road:g[i]){
            ans=min(ans,road.second);
            dfs(road.first, g, vis, ans);
        }
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> g(n);
        for(auto road: roads){
            g[road[0]-1].push_back({road[1]-1,road[2]});
            g[road[1]-1].push_back({road[0]-1,road[2]});
        }
        int ans = INT_MAX;
        vector<int> vis(n,0);
        dfs(0,g,vis,ans);
        return ans;
    }
};