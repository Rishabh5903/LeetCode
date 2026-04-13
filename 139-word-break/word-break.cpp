class Solution {
public:
    vector<int> dp;
    bool solve(int i, string& s, vector<string>& wordDict){
        if(s.size() == i)return dp[i]=1;
        if(dp[i] != -1) return dp[i];
        for(string& w:wordDict){
            int temp = i;
            if(s.size() - temp < w.size()) continue;
            for(int j=0;j<w.size();j++){
                if(s[temp]!=w[j]) break;
                temp++;
            }
            if(temp == (i+w.size())) if(solve(temp, s, wordDict)) return dp[i] = 1;
        }

        return dp[i]=0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        // if(!s.size()) return true;
        dp.resize(s.size()+1, -1);
        // for(string& w:wordDict){
            if(solve(0, s, wordDict)) return true;
        // }
        return false;
    }
};