class Solution {
public:
    int secondMinimum(int n, vector<vector<int>>& edges, int time, int change) {
        vector<vector<int>> adj(n + 1);
        for (auto& edge : edges) {
            adj[edge[0]].push_back(edge[1]);
            adj[edge[1]].push_back(edge[0]);
        }

        vector<int> dist(n + 1, INT_MAX);
        vector<int> second_dist(n + 1, INT_MAX);
        dist[1] = 0;

        queue<pair<int, int>> q;
        q.push({1, 0});

        while (!q.empty()) {
            int node = q.front().first;
            int d = q.front().second;
            q.pop();

            for (int neighbor : adj[node]) {
                if (d + 1 < dist[neighbor]) {
                    second_dist[neighbor] = dist[neighbor];
                    dist[neighbor] = d + 1;
                    q.push({neighbor, dist[neighbor]});
                } else if (d + 1 > dist[neighbor] && d + 1 < second_dist[neighbor]) {
                    second_dist[neighbor] = d + 1;
                    q.push({neighbor, second_dist[neighbor]});
                }
            }
        }

        int first = dist[n];
        int second = second_dist[n] == INT_MAX ? first + 2 : second_dist[n];

        int total_time = 0;

        for (int i = 0; i < second; i++) {
            if ((total_time / change) % 2 == 1) {
                total_time = ((total_time / change) + 1) * change;
            }
            total_time += time;
        }

        return total_time;
    }
};
