class Solution {
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        vector<vector<int>> cost(n, vector<int>(n, 1e9));

        for (int i = 0; i < n; i++) {
            cost[i][i] = 0;
        }

        for (auto& edge : edges) {
            int u = edge[0];
            int v = edge[1];
            int w = edge[2];
            cost[u][v] = w;
            cost[v][u] = w;
        }

        // Floyd Warshall Algorithm
        for (int via = 0; via < n; via++) {
            for (int i = 0; i < n; i++) {
                for (int j = 0; j < n; j++) {
                    cost[i][j] = min(cost[i][j], cost[i][via] + cost[via][j]);
                }
            }
        }

        int cntNode = INT_MAX; // random value (initialized with maximum value)
        int cityNum = INT_MAX; // random value (initialized with maximum value)

        // calculating the city with the smallest number of neighbors at a distanceThreshold
        for (int i = n - 1; i >= 0; i--) {
            int cnt = 0;
            for (int j = 0; j < n; j++) {
                if (cost[i][j] <= distanceThreshold) {
                    cnt++;
                }
            }
            if (cntNode > cnt) {
                cntNode = cnt;
                cityNum = i;
            }
        }

        return cityNum;
    }
};