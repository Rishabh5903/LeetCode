class Solution {
public:
void dfs(vector<vector<int>>& g,int i){
    for(int j=0;j<g.size();j++){
        if(g[i][j]){
            g[i][j]=0;dfs(g,j);
        }
    }
}
    int findCircleNum(vector<vector<int>>& g) {
        int n=g.size();
        int ans=0;
        for(int i=0;i<n;i++){
            if(g[i][i]==0)continue;
            ans++;
            dfs(g,i);
        }
        return ans;
    }
};