class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char,int> prev;
        int start=0;
        int ans=0;
        for(int i=0;i<s.size();i++){
            if(prev.find(s[i])!=prev.end() && prev[s[i]]>=start){
                start=prev[s[i]]+1;
                
            }
            prev[s[i]]=i;
            ans=max(ans,i-start+1);
        }
        return ans;
    }
};