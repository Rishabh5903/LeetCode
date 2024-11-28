#include <deque>
#include <vector>
#include <limits.h>
using namespace std;

class Solution {
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        int m = grid.size(), n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX)); // Distance array
        deque<pair<int, int>> dq; // Deque for 0-1 BFS
        
        // Initialize
        dist[0][0] = 0;
        dq.push_front({0, 0});
        
        // Directions for moving up, down, left, right
        vector<int> dx = {0, 0, 1, -1};
        vector<int> dy = {1, -1, 0, 0};
        
        while (!dq.empty()) {
            auto [x, y] = dq.front();
            dq.pop_front();
            
            for (int d = 0; d < 4; d++) {
                int nx = x + dx[d];
                int ny = y + dy[d];
                
                // Check boundaries
                if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                    int weight = grid[nx][ny];
                    
                    // Relax the edge
                    if (dist[x][y] + weight < dist[nx][ny]) {
                        dist[nx][ny] = dist[x][y] + weight;
                        
                        // Push to deque based on weight
                        if (weight == 0) {
                            dq.push_front({nx, ny});
                        } else {
                            dq.push_back({nx, ny});
                        }
                    }
                }
            }
        }
        
        // Return the minimum obstacles to reach bottom-right corner
        return dist[m - 1][n - 1];
    }
};
