class Solution {
public:
int dp[101][101];
int help(int i,int m,vector<int>& piles,vector<int>& psum){
    if(i>=piles.size())return dp[i][m]=0;
    if(dp[i][m]!=-1)return dp[i][m];
    int num=min(i+2*m,static_cast<int>(piles.size()));
    for(int x=i;x<(num);x++){
        dp[i][m]=max(dp[i][m],0-psum[i]+psum.back()-help(x+1,max(m,x-i+1),piles,psum));
    }
    return dp[i][m];

}
    int stoneGameII(vector<int>& piles) {memset(dp,-1,sizeof(dp));
    vector<int> psum(piles.size()+1,0);
    for(int i=0;i<piles.size();i++){
        psum[i+1]=psum[i]+piles[i];
    }
    return help(0,1,piles,psum);
        
    }
};