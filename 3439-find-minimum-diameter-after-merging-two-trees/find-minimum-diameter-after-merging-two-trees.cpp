class Solution {
public:
    vector<vector<int>> g;
    vector<int> par;
    pair<int,int> dfs(int i,int p=-1,int curr=0){
        par[i]=p;
        pair<int,int> ans={curr,i};
        for(int j:g[i]){
            if(j!=p){
                ans=max(ans,dfs(j,i,curr+1));
            }
        }
        return ans;

    }
    int minimumDiameterAfterMerge(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        int n=edges1.size()+1,m=edges2.size()+1;
        par=vector<int>(n);
        g=vector<vector<int>>(n);
        for(auto i:edges1){g[i[0]].push_back(i[1]);g[i[1]].push_back(i[0]);}
        auto x=dfs(0);
        auto y=dfs(x.second);
        int ans1,ans2;ans1=y.first;
        par.clear();g.clear();
        par=vector<int>(m);
        g=vector<vector<int>>(m);
        for(auto i:edges2){g[i[0]].push_back(i[1]);g[i[1]].push_back(i[0]);}
        x=dfs(0);
        y=dfs(x.second);
        ans2=y.first;
        return max((ans2+1)/2+(ans1+1)/2+1,max(ans1,ans2));
    }
};