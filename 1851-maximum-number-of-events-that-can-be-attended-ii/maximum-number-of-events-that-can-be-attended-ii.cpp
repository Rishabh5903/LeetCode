class Solution {
public:

    int maxValue(vector<vector<int>>& events, int k) {
        int n=events.size();
        vector<vector<int>> dp(n+1,vector<int>(k+1,-1));
        
        sort(events.begin(),events.end());
        vector<int> start;
        for(auto i:events)start.push_back(i[0]);
        for(int i=0;i<n+1;i++)dp[i][0]=0;
        for(int j=1;j<=k;j++)dp[n][j]=0;
        for(int j=1;j<=k;j++)dp[n-1][j]=events[n-1][2];
        for(int i=n-2;i>=0;i--){
            for(int j=1;j<=k;j++){
                int ind=upper_bound(start.begin(),start.end(),events[i][1])-start.begin();
                dp[i][j]=max(dp[i][j],max(dp[ind][j-1]+events[i][2],dp[i+1][j]));
            }
        }
        return dp[0][k];
    }
};