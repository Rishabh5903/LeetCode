class Solution {
public:
    int minCut(string s) {
        int n = s.size();
        vector<vector<bool>> isPal(n, vector<bool>(n, false));
        for (int i = n - 1; i >= 0; --i) {
            for (int j = i; j < n; ++j) {
                isPal[i][j] = (s[i] == s[j]) &&
                              (j - i < 2 || isPal[i + 1][j - 1]);
            }
        }
        vector<int> cut(n, INT_MAX);
        for (int i = 0; i < n; ++i) {
            if (isPal[0][i]) {
                cut[i] = 0;
            } else {
                for (int j = 1; j <= i; ++j) {
                    if (isPal[j][i]) {
                        cut[i] = min(cut[i], cut[j - 1] + 1);
                    }
                }
            }
        }
        return cut[n - 1];
    }
};
