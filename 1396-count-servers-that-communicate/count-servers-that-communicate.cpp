class Solution {
public:
    int countServers(vector<vector<int>>& grid) {int n=grid.size(),m=grid[0].size();
        set<pair<int,int>> s;vector<pair<int,int>> temp;
    
        for(int i=0;i<n;i++){int cnt=0;temp.clear();
            for(int j=0;j<m;j++)if(grid[i][j]){cnt++;temp.push_back({i,j});}
            if(cnt>=2){while(temp.size()){s.insert(temp.back());temp.pop_back();}}
        }
        for(int j=0;j<m;j++){int cnt=0;temp.clear();
            for(int i=0;i<n;i++)if(grid[i][j]){cnt++;temp.push_back({i,j});}
            if(cnt>=2){while(temp.size()){s.insert(temp.back());temp.pop_back();}}
        }
        return s.size();
    }
};