class Solution {
public:
    string s;
    long long dp[20][2];

    long long f(long long pos, long long tight) {
        if (pos == s.size()) return 1;

        if (dp[pos][tight] != -1) return dp[pos][tight];

        long long limit = tight ? (s[pos] - '0') : 9;
        long long res = 0;

        for (long long d = 1; d <= limit; d++) {
            long long newTight = tight && (d == limit);
            res += f(pos + 1, newTight);
        }

        return dp[pos][tight] = res;
    }

    long long countDistinct(long long n) {
        s = to_string(n);
        long long len = s.size();

        long long res = 0;

        for (long long l = 1; l < len; l++) {
            res += pow(9, l);
        }

        memset(dp, -1, sizeof(dp));
        res += f(0, 1);

        return res;
    }
};