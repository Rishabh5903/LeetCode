class Solution {
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        vector<vector<int>> g1(1001),g2(1001);int n=edges1.size()+1;
        for(auto i:edges1){g1[i[0]].push_back(i[1]);g1[i[1]].push_back(i[0]);}
        for(auto i:edges2){g2[i[0]].push_back(i[1]);g2[i[1]].push_back(i[0]);}
        vector<int> n1(1001),n2(1001);
        queue<int> q;vector<int> dist(1001);vector<int> vis(1001);
        for(int i=0;i<=n;i++){
            for(int j=0;j<=n;j++){vis[j]=0;dist[i]=0;}
            while(q.size())q.pop();q.push(i);n1[i]=1;
            while(q.size() && dist[q.front()]<k){
                int j=q.front();q.pop();vis[j]=1;
                for(int p:g1[j])if(!vis[p]){dist[p]=dist[j]+1;if(dist[p]<=k)n1[i]++;q.push(p);vis[p]=1;}
                // dist++;
            }
        }
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=1000;j++){vis[j]=0;dist[i]=0;}
            while(q.size())q.pop();q.push(i);n2[i]=1;
            while(q.size() && dist[q.front()]<(k-1)){
                int j=q.front();q.pop();vis[j]=1;
                for(int p:g2[j])if(!vis[p]){dist[p]=dist[j]+1;if(dist[p]<=k)n2[i]++;q.push(p);vis[p]=1;}
                // dist++;
            }
        }
    vector<int> ans(n);
    int maxo=(k ? *max_element(n2.begin(),n2.end()) : 0);
    for(int i=0;i<n;i++)ans[i]=n1[i]+maxo;
    return ans;

    }
};