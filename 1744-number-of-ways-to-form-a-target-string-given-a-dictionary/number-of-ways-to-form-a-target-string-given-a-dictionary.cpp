class Solution {
public:
const long long MOD=1e9+7;
    long long numWays(vector<string>& words, string target) {
        long long n=words[0].size(),m=target.size();
        vector<vector<long long>> dp(n+1,vector<long long>(m+1,0));
        map<vector<long long>,long long> mp;
        for(long long i=0;i<words.size();i++){
            for(long long j=0;j<n;j++)mp[{j,words[i][j]-'a'}]++;
        }
        for(long long i=n-1;i>=0;i--){
            for(long long j=m-1;j>=0;j--){
                if(j==(m-1))dp[i][j]=(mp[{i,target[j]-'a'}]+dp[i+1][j])%MOD;
                else{
                    dp[i][j]=((mp[{i,target[j]-'a'}]*dp[i+1][j+1])%MOD+dp[i+1][j])%MOD;
                }
            }
        }
        return dp[0][0];
    }
};