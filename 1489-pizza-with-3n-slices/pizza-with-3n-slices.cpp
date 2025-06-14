class Solution {
public:
    int dp[501][170][2];
    int solve(vector<int>& slices,int i,int rem,int flag){
        if(rem==0)return dp[i][rem][flag]=0;
        if(i>=slices.size() || ((i==slices.size()-1) && flag))return INT_MIN;
        if(dp[i][rem][flag]!=-1)return dp[i][rem][flag];
        return dp[i][rem][flag]=max(solve(slices,i+1,rem,(i==0 ? 0 : flag)),slices[i]+solve(slices,i+2,rem-1,(i==0 ? 1 : flag)));
    }
    int maxSizeSlices(vector<int>& slices) {
        int n=slices.size();
        memset(dp,-1,sizeof(dp));
        return solve(slices,0,n/3,0);
    }
};