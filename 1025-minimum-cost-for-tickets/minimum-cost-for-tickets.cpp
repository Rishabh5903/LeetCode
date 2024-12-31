class Solution {
    int dp[366];
    int solve(int i,vector<int>& days, vector<int>& c){
        if(i>=days.size())return 0;
        if(dp[i]!=-1)return dp[i];
        int ind1=lower_bound(days.begin()+i+1,days.end(),days[i]+1)-days.begin();
        int ind2=lower_bound(days.begin()+i+1,days.end(),days[i]+7)-days.begin();
        int ind3=lower_bound(days.begin()+i+1,days.end(),days[i]+30)-days.begin();
        return dp[i]=min(c[0]+solve(ind1,days,c),min(c[1]+solve(ind2,days,c),c[2]+solve(ind3,days,c)));
    }
public:
    int mincostTickets(vector<int>& days, vector<int>& c) {
        memset(dp,-1,sizeof(dp));
        return solve(0,days,c);
    }
};