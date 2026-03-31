class Solution {
public:
    bool chk(int i, int j, int k, int dir, vector<vector<char>>& board, string& s){
        if(k==s.size()){
            if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || (board[i][j]=='#')) return true;
            else return false;
        }
        if(i<0 || i>=board.size() || j<0 || j>=board[0].size() || (board[i][j]!=' ' && board[i][j]!=s[k])) return false;
        if(dir==1){
            return chk(i+1,j,k+1,1,board,s);
        }
        else if(dir==-1){
            return chk(i-1,j,k+1,-1,board,s);
        }
        else if(dir==2){
            return chk(i,j+1,k+1,2,board,s);
        }
        else if(dir==-2){
            return chk(i,j-1,k+1,-2,board,s);
        }
        return true;
    }
    bool placeWordInCrossword(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++){
            for(int j=0;j<board[0].size();j++){
                if((i==0 || board[i-1][j]=='#') && chk(i,j,0,1,board,word))return true;
                else if((j==0 || board[i][j-1]=='#') && chk(i,j,0,2,board,word))return true;
                else if((i==(board.size()-1) || board[i+1][j]=='#') && chk(i,j,0,-1,board,word))return true;
                else if((j==(board[0].size()-1) || board[i][j+1]=='#') && chk(i,j,0,-2,board,word))return true;

            }
        }
        return false;
    }
};