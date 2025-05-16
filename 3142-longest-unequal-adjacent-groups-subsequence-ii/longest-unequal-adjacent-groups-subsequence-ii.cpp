class Solution {
public:
    int dp[1001][1001];
    bool chk(int i,int j,vector<string>& words,vector<int>& groups){
        int n=words[i].size();
        if(words[j].size()!=n || groups[i]==groups[j])return 0;
        int cnt=0;
        for (int k=0;k<n;k++){
            if(cnt>=2)break;
            if(words[i][k]!=words[j][k])cnt++;
        }
        if(cnt==1)return 1;
        else return 0;
            
    }
    int solve(int i,int j,int prev,vector<string>& words, vector<int>& groups){
        if(dp[i][j]!=-1)return dp[i][j];
        if(j==words.size())return dp[i][j]=1;
        if(chk(prev,j,words,groups)){
            // prev=j;
            return dp[i][j]=max(1+solve(j,j+1,j,words,groups),solve(i,j+1,prev,words,groups));
        }
        else return dp[i][j]=solve(i,j+1,prev,words,groups);
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n=words.size();
        for(int i=0;i<1000;i++){
                    for(int j=0;j<1000;j++){
            dp[i][j]=-1;
        }
        }
        for(int i=0;i<n;i++){
                    for(int j=0;j<n;j++){
            solve(i,j,i,words,groups);
        }
        }
        
    vector<string>ans={};
        for(int i=0;i<n;i++){
            vector<string>temp={words[i]};int prev=i;
            for(int j=i+1;j<n;j++){
                if( chk(prev,j,words,groups) && (dp[prev][j]==1+dp[j][j+1] || (i==n-2 && j==n-1))){
                    temp.push_back(words[j]);prev=j;
                }
            }
            if(temp.size()>ans.size())ans=temp;
        }
        return ans;
    }
};