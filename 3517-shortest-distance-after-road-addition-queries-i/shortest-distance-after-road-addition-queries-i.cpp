class Solution {
public:
int dp[501][501];
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        n--;
        memset(dp,-1,sizeof(dp));
        vector<int> ans;
        for(int i=0;i<=n;i++){
            for(int j=i;j<=n;j++){
                dp[i][j]=j-i;
            }
        }
        for(auto i:queries){
            // dp[i[0]][i[1]]=1;
            // dp[0][n]=min(dp[0][n],dp[0][i[0]]+dp[i[1]][n]+1);
            
            for(int j=0;j<=i[0];j++){
                for(int k=i[1];k<=n;k++){
                    dp[j][k]=min(dp[j][k],dp[j][i[0]]+dp[i[1]][k]+1);
                }
            }
            ans.push_back(dp[0][n]);
        }
        return ans;
    }
};