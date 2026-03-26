class Solution {
public:
bool valid(string& a, string& b){
    int diff=0;
    int i=0, j=0;
    while(j<b.size()){
        if(a[i]!=b[j]){
            diff++;
            j++;
        }
        else {i++;j++;}
    }
    return (diff==1);
}
    int longestStrChain(vector<string>& words) {
        int n=words.size();
        vector<pair<int,string>> v;
        for(string& s:words)v.push_back({s.size(),s});
        sort(v.begin(), v.end());
        vector<int> dp(n,1);
        int ans=1;
        for(int i=n-2;i>=0;i--){
            // string curr=words[i];
            for(int j=i+1;j<n;j++){
                if((v[j].second.size() - v[i].second.size() == 1) && (valid(v[i].second, v[j].second))){
                    dp[i]=max(dp[i], 1 + dp[j]);
                }
            }
            ans = max(ans, dp[i]);
        }
        return ans;
    }
};