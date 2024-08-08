class Solution {
public:
    vector<vector<int>> spiralMatrixIII(int rows, int cols, int r, int c) {
        int right=1,left=1,up=1,down=1;
        int a=r,b=c;
        vector<vector<int>> ans;ans.push_back({r,c});
        while(ans.size()<rows*cols){
            for(int i=b+1;i<min(cols,b+2*right);i++)if(a>=0 && a<rows && i>=0 && i<cols)ans.push_back({a,i});b=b+2*right-1;right++;
            for(int i=a+1;i<min(rows,a+2*down);i++)if(b>=0 && b<cols && i>=0 && i<rows)ans.push_back({i,b});a=a+2*down-1;down++;
            for(int i=b-1;i>=max(0,b-(2*left));i--)if(a>=0 && a<rows && i>=0 && i<cols)ans.push_back({a,i});b=b-(2*left);left++;
            for(int i=a-1;i>=max(0,a-(2*up));i--)if(b>=0 && b<cols && i>=0 && i<rows)ans.push_back({i,b});a=a-(2*up);up++;
        }return ans;

    }
};