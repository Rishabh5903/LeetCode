class Solution {
public:
    long long maximumTotalDamage(vector<int>& power) {
        vector<pair<int,int>> powfr;
        sort(power.begin(),power.end());
        for(int i:power){
            if(powfr.size() && powfr.back().first==i)powfr.back().second++;
            else powfr.push_back({i,1});
        }
        int n=powfr.size();
        vector<long long> dp(n,-1);
        for(int i=n-1;i>=0;i--){
            long long curr = (1LL * powfr[i].first) * (1LL * powfr[i].second);
            if(i+1<n && powfr[i+1].first>powfr[i].first+2)curr+=dp[i+1];
            else if(i+2<n && powfr[i+2].first>powfr[i].first+2)curr+=dp[i+2];
            else if(i+3<n) curr+=dp[i+3];
            dp[i]=max(dp[i],max(curr,(i+1<n ? dp[i+1] : 0)));
            
        }
        return dp[0];

    }
};