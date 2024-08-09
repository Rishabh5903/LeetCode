class Solution {
public:
bool check(int i,int j,vector<vector<int>>& grid){
    int ans=1;
    vector<int> fr(16);vector<int> v;
    v.push_back((grid[i][j]+grid[i+1][j]+grid[i+2][j])); v.push_back((grid[i][j+1]+grid[i+1][j+1]+grid[i+2][j+1]));
    v.push_back((grid[i][j+2]+grid[i+1][j+2]+grid[i+2][j+2]));
    v.push_back((grid[i][j]+grid[i][j+1]+grid[i][j+2]));
    v.push_back((grid[i+1][j]+grid[i+1][j+1]+grid[i+1][j+2]));
    v.push_back((grid[i+2][j]+grid[i+2][j+1]+grid[i+2][j+2]));
    v.push_back((grid[i][j]+grid[i+1][j+1]+grid[i+2][j+2]));
    v.push_back((grid[i+2][j]+grid[i+1][j+1]+grid[i][j+2]));
    sort(v.begin(),v.end());ans&=(v[0]==v.back());
    fr[grid[i][j]]++;fr[grid[i][j+1]]++;fr[grid[i][j+2]]++;fr[grid[i+1][j]]++;
    fr[grid[i+1][j+1]]++;
    fr[grid[i+1][j+2]]++;fr[grid[i+2][j]]++;fr[grid[i+2][j+1]]++;fr[grid[i+2][j+2]]++;
    for(int i=1;i<=9;i++)if(fr[i]!=1){ans=0;break;}
    return ans;

}
    int numMagicSquaresInside(vector<vector<int>>& grid) {
        int ans=0;
        if(grid.size()<3 || grid[0].size()<3)return 0;
        for(int i=0;i<=grid.size()-3;i++){
            for(int j=0;j<=grid[0].size()-3;j++){
                ans+=check(i,j,grid);
            }
        }return ans;
    }
};