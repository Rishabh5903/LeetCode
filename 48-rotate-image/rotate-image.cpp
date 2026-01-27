class Solution {
public:
    void rotate(vector<vector<int>>& matrix) {
        int n=matrix.size();
        for(int i=0;i<(matrix.size())/2;i++){
            for(int j=0;j<(matrix[0].size())/2;j++){
                swap(matrix[i][j],matrix[j][n-i-1]);
                swap(matrix[n-i-1][n-j-1],matrix[n-j-1][i]);
                swap(matrix[i][j],matrix[n-i-1][n-j-1]);
            }
        }
        if(n%2){
            
            int j=(n+1)/2-1;
            for(int i=0;i<n/2;i++){
                swap(matrix[i][j],matrix[j][n-i-1]);
                swap(matrix[n-i-1][n-j-1],matrix[n-j-1][i]);
                swap(matrix[i][j],matrix[n-i-1][n-j-1]);
            }
        }

    }
};