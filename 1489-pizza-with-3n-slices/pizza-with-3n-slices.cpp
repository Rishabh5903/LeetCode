class Solution {
public:
    int dp[501][170];

    int solve(vector<int>& slices, int i, int rem, int end) {
        if (rem == 0) return 0;
        if (i > end) return INT_MIN;
        if (dp[i][rem] != -1) return dp[i][rem];

        int skip = solve(slices, i + 1, rem, end);
        int takeNext = solve(slices, i + 2, rem - 1, end);
        int take = (takeNext == INT_MIN ? INT_MIN : slices[i] + takeNext);

        return dp[i][rem] = max(skip, take);
    }

    int maxSizeSlices(vector<int>& slices) {
        int n = slices.size();
        int k = n / 3;

        memset(dp, -1, sizeof(dp));
        int ans1 = solve(slices, 1, k, n - 1);

        memset(dp, -1, sizeof(dp));
        int suffix = solve(slices, 2, k - 1, n - 2);
        int ans2 = (suffix == INT_MIN ? INT_MIN : slices[0] + suffix);

        return max(ans1, ans2);
    }
};
