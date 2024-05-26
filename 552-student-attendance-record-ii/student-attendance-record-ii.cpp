class Solution {
public:
int mod=1e9+7;
int dp[100001][3][2];

    int solve(int i,int j,int k,int& n){
        if(i==n)return dp[i][j][k]=1;
        if(dp[i][j][k]!=-1){return dp[i][j][k];
        }
        if(j==0 && k==0)dp[i][j][k]=solve(i+1,2,0,n)%mod;
        else if(j==0 && k==1)dp[i][j][k]=((solve(i+1,2,1,n)%mod)+(solve(i+1,2,0,n)%mod))%mod;
        else if(j==1 && k==0)dp[i][j][k]=((solve(i+1,2,0,n)%mod)+(solve(i+1,0,0,n)%mod))%mod;
        else if(j==1 && k==1)dp[i][j][k]=((((solve(i+1,2,1,n)%mod)+(solve(i+1,0,1,n)%mod))%mod)+(solve(i+1,2,0,n)%mod))%mod;
        else if(j==2 && k==0)dp[i][j][k]=((solve(i+1,2,0,n)%mod)+(solve(i+1,1,0,n)%mod))%mod;
        else if(j==2 && k==1)dp[i][j][k]=((((solve(i+1,2,1,n)%mod)+(solve(i+1,1,1,n)%mod))%mod)+(solve(i+1,2,0,n)%mod))%mod;
        return dp[i][j][k];
    }
    int checkRecord(int n) {
        memset(dp,-1,sizeof(dp));
    return solve(0,2,1,n);
        
    }
};