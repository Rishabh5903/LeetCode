class Solution {
public:
    int longestPalindromeSubseq(string s) {
        int n = s.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=n-1;i>=0;i--){
            for(int j=0;j<n;j++){
                if(i>j)continue;
                dp[i][j] = max( dp[i][j], 
                                max(
                                    max(i<n-1 ? dp[i+1][j] : 0, j ? dp[i][j-1] : 0), 
                                    ((s[i]==s[j])*(i==j ? 1 : 2) + ((i<n-1 && j) ? dp[i+1][j-1] : 0))
                                    )
                                    );
            }
        }
        return dp[0][n-1];
    }
};