class Solution {
public:
    void dfs(int i,int par,vector<int>& vis,vector<set<int>>& g,int temp,int& ans){
        if(vis[i]){ans+=temp-1;return;}
        vis[i]=1;
        for(int j:g[i])if(j!=par)dfs(j,i,vis,g,temp+1,ans);
        // if(!g[i].size())ans+=temp;
    }
    int minSwapsCouples(vector<int>& row) {
        int n=row.size()/2;
        vector<set<int>> g(n);
        int a=0,b=0;
        for(int i=0;i<n;i++){
            for(int j=1;j<=n;j++){
                if(row[2*j-2]==(2*i) || row[2*j-1]==(2*i))a=j;
                if(row[2*j-2]==(2*i+1) || row[2*j-1]==(2*i+1))b=j;
            }
            if(a!=b)g[a-1].insert(b-1);
            if(a!=b)g[b-1].insert(a-1);
        }
        int ans=0;
        vector<int> vis(n,0);
        for(int i=0;i<n;i++){
            if(!vis[i])dfs(i,-1,vis,g,0,ans);
        }
        int cnt=0;
        for(auto i:g)if(i.size()==1)cnt++;
        ans+=cnt/2;
        return ans;
    };
};