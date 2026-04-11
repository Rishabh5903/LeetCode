class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        unordered_map<char, int> prev;
        int start = 0;
        int ans=0;
        for(int i=0;i<s.size(); i++){
            char c = s[i];
            if(prev.count(c) && prev[c]>=start){
                start = prev[c] + 1;
                
            }
            prev[c]=i;
            ans= max(ans, i-start + 1);

        }
        return ans;
    }
};