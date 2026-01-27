class Solution {
public:
    void rot(int i, int j, vector<vector<int>>& grid, int& rem, queue<vector<int>>& rotten){
        if(i>=0 && i<grid.size() && j>=0 && j<grid[0].size() && grid[i][j]==1){rem--;grid[i][j]=2;rotten.push({i,j});}
    }
    int orangesRotting(vector<vector<int>>& grid) {
        int ans=0,rem=0;
        for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++)if(grid[i][j]==1)rem++;
        }
        queue<vector<int>> rotten;
            for(int i=0;i<grid.size();i++){
            for(int j=0;j<grid[0].size();j++){
                if(grid[i][j]==2){
                    rotten.push({i,j});
                    
                }
            }}
            while(rotten.size()){
                if(rem>0)ans++;
                int sz=rotten.size();
                for(int k=0;k<sz;k++){
                int i = rotten.front()[0];
                int j = rotten.front()[1];
                rotten.pop();
                    rot(i+1,j,grid,rem,rotten);
                    rot(i-1,j,grid,rem,rotten);
                    rot(i,j+1,grid,rem,rotten);
                    rot(i,j-1,grid,rem,rotten);
                }
            }
        
        return rem<=0 ? (ans) : -1;
    }
};