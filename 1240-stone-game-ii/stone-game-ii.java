class Solution {
    public int stoneGameII(int[] piles) {
        int n = piles.length;
        int [][] dp = new int[n+2][n+2];
        int[] psum = new int[n+1];
        for(int i=1;i<=n;i++){
            psum[i] = psum[i-1] + piles[i-1];
        }
        for(int i=n;i>=1;i--){
            int total = psum[n] - psum[i - 1];
            int rem = n - i + 1;
            for(int m=n;m>=1;m--){
                if (2 * m >= rem) {
                    dp[i][m] = total;
                    continue;
                }
                for(int x=1;x<=Math.min(2*m, n - i +1);x++){
                    dp[i][m] = Math.max(dp[i][m], total - dp[i+x][Math.max(m,x)]);
                }
            }
        }
        return dp[1][1];
    }
}