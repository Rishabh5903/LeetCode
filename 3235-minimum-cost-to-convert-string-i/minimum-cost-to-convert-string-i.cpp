class Solution {
public:
    long long minimumCost(string source, string target, vector<char>& original, vector<char>& changed, vector<int>& cost) {
        map<pair<char, char>, long long> costMap;
        for (int i = 0; i < original.size(); ++i) {
            char from = original[i];
            char to = changed[i];
            long long conversionCost = cost[i];
            if (costMap.find({from, to}) == costMap.end()) {
                costMap[{from, to}] = conversionCost;
            } else {
                costMap[{from, to}] = min(costMap[{from, to}], conversionCost);
            }
        }

        // Initialize a 26x26 DP table to store minimum conversion costs between any two characters
        vector<vector<long long>> dp(26, vector<long long>(26, LLONG_MAX));
        for (char c = 'a'; c <= 'z'; ++c) {
            dp[c - 'a'][c - 'a'] = 0; // Cost to convert a character to itself is 0
        }

        // Update DP table with direct conversion costs
        for (const auto& entry : costMap) {
            char from = entry.first.first;
            char to = entry.first.second;
            dp[from - 'a'][to - 'a'] = min(dp[from - 'a'][to - 'a'], entry.second);
        }

        // Apply Floyd-Warshall to find the minimum conversion cost between all pairs of characters
        for (char k = 'a'; k <= 'z'; ++k) {
            for (char i = 'a'; i <= 'z'; ++i) {
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (dp[i - 'a'][k - 'a'] != LLONG_MAX && dp[k - 'a'][j - 'a'] != LLONG_MAX) {
                        dp[i - 'a'][j - 'a'] = min(dp[i - 'a'][j - 'a'], dp[i - 'a'][k - 'a'] + dp[k - 'a'][j - 'a']);
                    }
                }
            }
        }

        // Calculate the total minimum cost to convert source to target
        long long totalCost = 0;
        for (int i = 0; i < source.size(); ++i) {
            char s = source[i];
            char t = target[i];
            if (s != t) {
                if (dp[s - 'a'][t - 'a'] == LLONG_MAX) {
                    return -1; // If conversion is not possible
                }
                totalCost += dp[s - 'a'][t - 'a'];
            }
        }

        return totalCost;
    }
};