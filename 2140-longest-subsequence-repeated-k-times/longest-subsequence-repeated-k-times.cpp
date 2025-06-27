class Solution {
public:
    bool chk(string& s,string& temp,int& k){
        int cnt=0;int j=0;
        for(int i=0;i<s.size();i++){
            if(s[i]==temp[j])j++;
            if(j==temp.size()){cnt++;j=0;}
            if(cnt==k)return true;
        }
        return cnt>=k;
    }
    void solve(string& ans,string& s,string& temp,int& k,vector<int>& fr,vector<int>& curr){
        if(chk(s,temp,k) && ans.size()<temp.size())ans=temp;
        if(temp.size()==8)return;
        for(int i=25;i>=0;i--){
            if(curr[i]<(fr[i]/k)){
                temp+=('a'+i);curr[i]++;solve(ans,s,temp,k,fr,curr);
                temp.pop_back();curr[i]--;
            }
        }
    }
    string longestSubsequenceRepeatedK(string s, int k) {
        string ans="";
        vector<int> fr(26,0);
        for(char c:s)fr[c-'a']++;
        vector<int> curr(26,0);
        string temp="";
        solve(ans,s,temp,k,fr,curr);
        return ans;
    }
};