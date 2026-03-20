class Solution {
public:
    vector<int> par;
    vector<int> num;

    int find(int i){
        if(i==par[i]) return i;
        else return find(par[i]);
    }

    void join(int i, int j){
        int p1 = find(i);
        int p2 = find(j);
        if(p1==p2) return;
        if(num[p1] < num[p2]) swap(p1,p2);
        num[p1]+=num[p2];
        par[p2] = p1;
    }
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n=vals.size();
        par.resize(n); for(int i=0;i<n;i++)par[i]=i;
        num.resize(n,1);
        map<int, vector<int>> same;
        vector<vector<int>> adj(n);
        int ans = 0;
        for(int i=0;i<n;i++) same[vals[i]].push_back(i);
        for(auto& edge:edges){
            int u = edge[0], v = edge[1];
            if(vals[u]>=vals[v]){
                adj[u].push_back(v);
            }
            else adj[v].push_back(u);
        }

        for(auto& [val, nodes] : same){
            for(int u:nodes){
                for(int v:adj[u]){
                    join(u,v);
                }

            }
            unordered_map<int,int> count;
            for(int u:nodes){
                count[find(u)]++;
            }
            ans+=nodes.size();
            for(auto& [par, cnt]:count){
                ans+=(cnt*(cnt-1))/2;
            }
            
        }
        return ans;
    }
};