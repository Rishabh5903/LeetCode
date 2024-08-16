class Solution {
public:
    int maxDistance(vector<vector<int>>& arrays) {
        vector<vector<int>> v1,v2;
        for(int i=0;i<arrays.size();i++){v1.push_back({arrays[i][0],i});v2.push_back({arrays[i].back(),i});}
        sort(v1.begin(),v1.end());
        sort(v2.rbegin(),v2.rend());
        return (v1[0][1]!=v2[0][1] ? (v2[0][0]-v1[0][0]) : max(abs(v2[1][0]-v1[0][0]),abs(v2[0][0]-v1[1][0])));
    }
};