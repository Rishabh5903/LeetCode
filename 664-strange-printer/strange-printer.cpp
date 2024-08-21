#include <vector>
#include <string>
#include <algorithm>

class Solution {
public:
    std::vector<std::vector<int>> dp;

    int solve(int i, int j, string& s) {
        if (i > j) return 0;
        if (dp[i][j] != -1) return dp[i][j];

        dp[i][j] = solve(i + 1, j, s) + 1;  

        for (int k = i + 1; k <= j; ++k) {
            if (s[k] == s[i]) {
                dp[i][j] = std::min(dp[i][j], solve(i, k - 1, s) + solve(k + 1, j, s));
            }
        }

        return dp[i][j];
    }

    int strangePrinter(string s) {
        int n = s.size();
        dp = std::vector<std::vector<int>>(n, std::vector<int>(n, -1));
        return solve(0, n - 1, s);
    }
};
