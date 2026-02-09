class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n,INT_MAX);
        priority_queue<vector<int>,vector<vector<int>>,greater<vector<int>>> q;
        time[k-1]=0;
        vector<int> vis(n,0);vis[k-1]=1;
        vector<vector<vector<int>>> g(n);
        for(auto edge:times){
            g[edge[0]-1].push_back({edge[2],edge[0]-1,edge[1]-1});
        }
        for(auto e:g[k-1]){
            q.push(e);
            vis[e[2]]=1;
        }
        while(q.size()){
            auto e=q.top();q.pop();
            int w=e[0],u=e[1],v=e[2];
            if(time[u]==INT_MAX)continue;
            if(time[v]>time[u]+w){
                time[v]=time[u]+w;
                for(auto e:g[v]){
                    // if(vis[e[2]])continue;
                    q.push(e);vis[e[2]]=1;
                }
            }
        }
        int ans=0;
        for(int i=0;i<n;i++){
            // if(i==(k-1))continue;
            if(time[i]==INT_MAX)return -1;
            else ans=max(ans,time[i]);
        }
        return ans;

    }
};