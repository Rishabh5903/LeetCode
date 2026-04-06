class Solution {
public:
    int solve(int i, vector<int>& start, vector<int>& end, string& s){
        int r = end[s[i]-'a'];
        for(int j=i;j<=r;j++){
            if(start[s[j]-'a'] < i)return -1;
            r=max(r, end[s[j]-'a']);
        }
        return r;
    }
    vector<string> maxNumOfSubstrings(string s) {
        vector<int> start(26,-1);
        vector<int> end(26,-1);
        for(int i=0;i<s.size();i++){
            if(start[s[i]-'a'] == -1)start[s[i]-'a']=i;
            end[s[i]-'a']=i;
        }
        vector<string> ans;
        int right=-1;
        for(int i=0;i<s.size();i++){
            if(i==start[s[i]-'a']){
                // if(i<right)continue;
                int new_right = solve(i,start,end,s);
                if(new_right!=-1){
                if(i>right){
                    ans.push_back("");
                }
                right=new_right;
                ans.back()=s.substr(i,right-i+1);
                }
            }
        }
        return ans;
        
    }
};