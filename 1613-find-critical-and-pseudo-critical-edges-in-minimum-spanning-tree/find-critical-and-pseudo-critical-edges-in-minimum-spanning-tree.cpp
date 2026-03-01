class Solution {
public:
    int mst(int& n,vector<multiset<pair<int,int>>>& g,vector<int>& edge){
        int ans=0,cnt = 1;
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> pq;
        vector<int> vis(n,0);
        if(edge.size()){
            vis[edge[0]]=1;
            vis[edge[1]]=1;
            cnt=2;
            ans+=edge[2];
            for(auto& p:g[edge[0]]){
            int w=p.first, j=p.second;
            if(!vis[j])pq.push({w,0,j});
        }
            for(auto& p:g[edge[1]]){
            int w=p.first, j=p.second;
            if(!vis[j])pq.push({w,0,j});
        }
        }
        else{
        vis[0]=1;

        for(auto& p:g[0]){
            int w=p.first, j=p.second;
            if(!vis[j])pq.push({w,0,j});
        }
        }
        while(pq.size() && cnt<n){
            auto t = pq.top();pq.pop();
            int w=t[0], i=t[1], j=t[2];
            // vis[j] = 1;
            
            if(!vis[j]){
                cnt++; ans+=w;
                vis[j]=1;
                for(auto& p:g[j]){
                    int w=p.first, k=p.second;
                    if(!vis[k])pq.push({w,j,k});
                }
            }
            
        }
        return cnt==n ? ans : -1;
    }
    vector<vector<int>> findCriticalAndPseudoCriticalEdges(int n, vector<vector<int>>& edges) {
        vector<multiset<pair<int,int>>> g(n);
        for(auto& edge:edges){
            g[edge[0]].insert({edge[2],edge[1]});
            g[edge[1]].insert({edge[2],edge[0]});
        }
        vector<int> empty={};
        
        vector<vector<int>> ans(2);
        int opt = mst(n,g,empty);
        if(opt==-1)return ans;
        for(int i=0;i<edges.size();i++){
            vector<int>& edge = edges[i];
            int temp = mst(n,g,edge);
            g[edge[0]].erase({edge[2],edge[1]});
            g[edge[1]].erase({edge[2],edge[0]});
            int curr = mst(n,g,empty);
            if(curr > opt || curr==-1)ans[0].push_back(i);
            else if(curr == opt && temp==opt)ans[1].push_back(i);

            g[edge[0]].insert({edge[2],edge[1]});
            g[edge[1]].insert({edge[2],edge[0]});
        }
        // return {{opt}};
        return ans;
    }
};