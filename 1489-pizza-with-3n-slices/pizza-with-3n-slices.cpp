class Solution {
public:
    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int K = n / 3;
        static int dp[502][170][2];
        for (int i = 0; i <= n+1; ++i) {
            for (int rem = 0; rem <= K; ++rem) {
                for (int f = 0; f < 2; ++f) {
                    dp[i][rem][f] = (rem == 0 ? 0 : INT_MIN);
                }
            }
        }
        for (int i = n - 1; i >= 0; --i) {
            for (int rem = 1; rem <= K; ++rem) {
                for (int f = 0; f < 2; ++f) {
                    if (i == n - 1 && f == 1) {
                        dp[i][rem][f] = INT_MIN;
                        continue;
                    }
                    int skip = dp[i + 1][rem][ i == 0 ? 0 : f ];
                    int nf = (i == 0 ? 1 : f);
                    // int take = INT_MIN;
                    // if (dp[i + 2][rem - 1][nf] != INT_MIN)
                    int take = slices[i] + dp[i + 2][rem - 1][nf];
                    dp[i][rem][f] = max(skip, take);
                }
            }
        }
        return dp[0][K][0];
    }
};
