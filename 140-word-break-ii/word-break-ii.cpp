class Solution {
public:
void dfs(int i,string temp,string curr,vector<string>& ans,map<string,int>& mp,string& s){
    if(i==s.size() ){
    //    if(mp[curr]) ans.push_back(temp+curr);
    if(curr=="")ans.push_back(temp);
       return;
    }
    curr+=s[i];
    if(mp[curr]){
        dfs(i+1,temp+curr+(i!=(s.size()-1) ? " " : ""),"",ans,mp,s);
    }
    dfs(i+1,temp,curr,ans,mp,s);

}
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        map<string,int> mp;for(string i:wordDict)mp[i]++;
        vector<string> ans;
        dfs(0,"","",ans,mp,s);
        return ans;
    }
};