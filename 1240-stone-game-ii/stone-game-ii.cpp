class Solution {
public:
    int stoneGameII(vector<int>& piles) {
        int n = piles.size();

        vector<vector<int>> dp(n + 2, vector<int>(n + 2, 0));
        vector<int> psum(n + 1, 0);

        for (int i = 1; i <= n; i++) {
            psum[i] = psum[i - 1] + piles[i - 1];
        }

        for (int i = n; i >= 1; i--) {
            for (int m = n; m >= 1; m--) {
                for (int x = 1; x <= min(2 * m, n - i + 1); x++) {
                    dp[i][m] = max(
                        dp[i][m],
                        -psum[i - 1] + psum[n] - dp[i + x][max(m, x)]
                    );
                }
            }
        }

        return dp[1][1];
    }
};