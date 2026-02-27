class Solution {
public:
vector<vector<int>> g;
vector<vector<int>> g1;
vector<int> vis;
stack<int> s;
    
    bool dfs(int i, vector<vector<int>>& g){
        vis[i]=1;
        for(int j:g[i]){
            if(vis[j]==1)return true;
            if(vis[j]==0){
                if(dfs(j,g))return true;
            }
        }
        vis[i]=2;
        s.push(i);
        return false;
    }
    vector<vector<int>> buildMatrix(int k, vector<vector<int>>& rowConditions, vector<vector<int>>& colConditions) {
        g.assign(k+1,{});
        g1.assign(k+1,{});
        vis.assign(k+1,0);
        while(!s.empty())s.pop();
        for(auto& i:rowConditions){
            g[i[0]].push_back(i[1]);
        }
        for(auto& i:colConditions){
            g1[i[0]].push_back(i[1]);
        }
        for(int i=1;i<=k;i++){
            if(vis[i]==0)if(dfs(i,g))return {};
        }
        vector<int> row;
        while(s.size()){row.push_back(s.top());s.pop();}
        vis.assign(k+1,0);
        for(int i=1;i<=k;i++){
            if(vis[i]==0)if(dfs(i,g1))return {};
        }
        vector<int> col;
        while(s.size()){col.push_back(s.top());s.pop();}
        vector<vector<int>> ans(k,vector<int>(k,0));
        for(int i=1;i<=k;i++){
            int r,c;
            for(int j=0;j<k;j++)if(row[j]==i){r=j;break;}
            for(int j=0;j<k;j++)if(col[j]==i){c=j;break;}
            ans[r][c]=i;
        }
        return ans;
    }
};