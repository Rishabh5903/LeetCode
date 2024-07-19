class Solution {
public:
    vector<int> luckyNumbers (vector<vector<int>>& matrix) {
        int n=matrix.size(),m=matrix[0].size();
        vector<int> maxo(m),mino(n);
        for(int i=0;i<n;i++){
            mino[i]=*min_element(matrix[i].begin(),matrix[i].end());
        }
        for(int j=0;j<m;j++){
            int temp=0;
            for(int i=0;i<n;i++){
                temp=max(temp,matrix[i][j]);
            }maxo[j]=temp;
        }
        vector<int> ans;
        for(int j=0;j<m;j++){
            for(int i=0;i<n;i++){
                if(matrix[i][j]==mino[i] && matrix[i][j]==maxo[j])ans.push_back(matrix[i][j]);
            }
        }return ans;
    }
};