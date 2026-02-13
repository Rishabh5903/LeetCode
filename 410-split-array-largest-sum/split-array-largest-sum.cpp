class Solution {
public:
    int splitArray(vector<int>& nums, int k) {
        int n=nums.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,INT_MAX));
        for(int i=0;i<=n;i++)dp[i][0]=INT_MAX;
        for(int i=0;i<=k;i++)dp[n][i]=0;
        for(int  i=n-1;i>=0;i--){
            for(int j=1;j<=k;j++){
                // if(k==1){
                //     int temp=nums[i];
                //     for(int l=i;l<n;l++){
                //         temp=max(temp,nums[l]);
                //         dp[i][k]=min(dp[i][k],temp);
                //     }
                // }
                // else{
                    int temp=0;
                    for(int l=i;l<=n-j;l++){
                        temp+=nums[l];
                        dp[i][j]=min(dp[i][j],max(temp,dp[l+1][j-1]));
                    }
                // }
            }
        }
        // return dp[3][1];
        return dp[0][k];
    }
};