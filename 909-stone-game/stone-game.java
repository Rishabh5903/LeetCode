class Solution {
    public boolean stoneGame(int[] piles) {
        int[][] dp = new int[piles.length+2][piles.length+2];
        int[] psum = new int[piles.length+1];
        for(int i=1;i<piles.length+1;i++){
            psum[i] = psum[i-1] + piles[i-1];
        }
        for(int i=piles.length;i>=1;i--){
            for(int j=1;j<=piles.length;j++){
                dp[i][j] = Math.max(piles[i-1] + psum[j] - psum[i] - dp[i+1][j], piles[j-1] + psum[j-1] - psum[i-1] - dp[i-1][j]);
            }
        }
        return (2*dp[1][piles.length] > psum[piles.length]);
    }
}