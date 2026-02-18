class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        vector<int> dp(n+2,0);
        for(int i=n-2;i>=0;i--){
            for(int j=i+1;j<n;j++){
                dp[i]=max(dp[i],dp[j+2]+prices[j]-prices[i]);
            }
            dp[i]=max(dp[i],dp[i+1]);
        }
        return dp[0];
    }
};