class Solution {
public:
    bool canPartition(vector<int>& nums) {
        int n=nums.size();
        int tot=accumulate(nums.begin(),nums.end(),0);
        if(tot%2)return false;
        tot/=2;
        bool dp[n+1][tot+1];

        memset(dp,false,sizeof(dp));
        for (int i = 0; i <= n; i++) {
            dp[i][0] = true;
        }
        for(int i=n-1;i>=0;i--){
            for(int j=1;j<=tot;j++){
                // if(i==n-1)if(nums[i]==j)dp[i][j]=true;
                // else{
                if(nums[i]<=j)dp[i][j]=(dp[i][j] || dp[i+1][j-nums[i]] || dp[i+1][j]);
                else dp[i][j]=(dp[i][j] || dp[i+1][j]);
                // }
                
            }
        }
        return dp[0][tot];
    }
};