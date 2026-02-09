class Solution {
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        vector<int> time(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>> q;

        vector<vector<pair<int,int>>> g(n);
        for(auto edge: times){
            g[edge[0]-1].push_back({edge[1]-1, edge[2]});
        }

        time[k-1] = 0;
        q.push({0, k-1});

        while(q.size()){
            auto [t, u] = q.top(); q.pop();
            if(t > time[u]) continue;

            for(auto [v, w] : g[u]){
                if(time[v] > time[u] + w){
                    time[v] = time[u] + w;
                    q.push({time[v], v});
                }
            }
        }

        int ans = 0;
        for(int i = 0; i < n; i++){
            if(time[i] == INT_MAX) return -1;
            ans = max(ans, time[i]);
        }
        return ans;
    }
};
