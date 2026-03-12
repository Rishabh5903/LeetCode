class Solution {
public:
    int racecar(int target) {
        vector<int> dp(target + 1, 1e9);
        dp[0] = 0;

        for(int i = 1; i <= target; i++){
            int n = log2(i) + 1;
            int curr = (1 << n) - 1;

            if(curr == i){
                dp[i] = n;
                continue;
            }

            dp[i] = min(dp[i], n + 1 + dp[curr - i]);

            for(int prev = 0; prev < n - 1; prev++){
                int back = (1 << prev) - 1;
                int pos = (1 << (n - 1)) - 1;
                int rem = i - (pos - back);
                dp[i] = min(dp[i], (n - 1) + 1 + prev + 1 + dp[rem]);
            }
        }

        return dp[target];
    }
};