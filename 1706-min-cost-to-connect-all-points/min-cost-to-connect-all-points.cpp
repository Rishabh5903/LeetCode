class Solution {
public:
vector<int> par;
vector<int> rank;
    int find(int i){
        if(i == par[i]) return i;
        return find(par[i]);
    }
    void join(int i, int j){
        int u = find(i);
        int v = find(j);
        if(u == v) return;
        if(rank[u] < rank[v]) swap(u,v);
        rank[u] += rank[v];
        par[v] = u;
    }
    int minCostConnectPoints(vector<vector<int>>& points) {
        int n = points.size();
        par.resize(n);
        for(int i=0; i<n; i++)par[i]=i;
        rank.resize(n, 1);
        int ans=0;
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        for(int i=0;i<n;i++){
            for(int j=0;j<n;j++){
                if(i==j)continue;
                int dist = abs(points[i][0] - points[j][0]) + abs(points[i][1] - points[j][1]);
                pq.push({dist, i, j});
            }
        }
        int cnt=0;
        while(cnt<n-1){
            auto e = pq.top(); pq.pop();
            if(find(e[1]) == find(e[2])) continue;
            cnt++;
            ans+=e[0];
            join(e[1], e[2]);
        }
        return ans;
    }
};
