class Solution {
public:
    bool dfs(int i, map<int, vector<int>>& mp, vector<int>& vis, vector<int>& stackVis) {
        if (stackVis[i]) return false;
        if (vis[i]) return true; 
        vis[i] = 1;
        stackVis[i] = 1; 
        
        for (int j : mp[i]) {
            if (!dfs(j, mp, vis, stackVis)) return false;
        }
        
        stackVis[i] = 0; 
        return true;
    }
    
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> vis(numCourses, 0);
        vector<int> stackVis(numCourses, 0);
        map<int, vector<int>> mp;
        
        for (auto& i : prerequisites) {
            mp[i[0]].push_back(i[1]);
        }
        
        for (int i = 0; i < numCourses; i++) {
            if (!vis[i]) {
                if (!dfs(i, mp, vis, stackVis)) return false;
            }
        }
        
        return true;
    }
};
