class Solution {
public:
    int maximumScore(vector<int>& scores, vector<vector<int>>& edges) {
        int n = scores.size();
        vector<priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>>>> pq(n);
        
        for(auto &edge:edges){
            int u=edge[0], v=edge[1];
            pq[u].push({scores[v], v});
            pq[v].push({scores[u], u});
            if(pq[u].size()>3)pq[u].pop();
            if(pq[v].size()>3)pq[v].pop();
        }

        int ans = -1;
        vector<int> v1,v2;

        for(auto& edge:edges){
            int u=edge[0], v=edge[1];
            
            vector<pair<int,int>> t1,t2;
            auto pu = pq[u], pv = pq[v];

            while(pu.size()){ t1.push_back(pu.top()); pu.pop(); }
            while(pv.size()){ t2.push_back(pv.top()); pv.pop(); }

            for(auto &a:t1){
                for(auto &b:t2){
                    int i=a.second, j=b.second;
                    if(i!=j && i!=v && j!=u){
                        ans=max(ans, scores[u]+scores[v]+scores[i]+scores[j]);
                    }
                }
            }
        }
        return ans;
    }
};