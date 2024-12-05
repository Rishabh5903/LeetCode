class Solution {
public:
    int dp[101][101];
    
    int solve(int i, int j, int& n, vector<int>& cuts) {
        if (i > j) return 0; // Base case: no cuts
        
        if (dp[i][j] != INT_MAX) return dp[i][j];
        
        int left = (i == 0 ? 0 : cuts[i - 1]);
        int right = (j == cuts.size() - 1 ? n : cuts[j+1]);
        
        for (int k = i; k <= j; k++) {
            int cost = right - left + solve(i, k - 1, n, cuts) + solve(k + 1, j, n, cuts);
            dp[i][j] = min(dp[i][j], cost);
        }
        
        return dp[i][j];
    }
    
    int minCost(int n, vector<int>& cuts) {
        sort(cuts.begin(), cuts.end());
        
        // Initialize dp array with a large value
        for (int i = 0; i < 101; i++) {
            for (int j = 0; j < 101; j++) {
                dp[i][j] = INT_MAX;
            }
        }
        
        return solve(0, cuts.size() - 1, n, cuts);
    }
};
