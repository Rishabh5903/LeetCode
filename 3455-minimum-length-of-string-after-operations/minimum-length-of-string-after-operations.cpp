class Solution {
public:
    int minimumLength(string s) {
        vector<int> fr(26);
        for(char c:s)fr[c-'a']++;
        int ans=0;
        for(int i:fr)if(i)if(i%2)ans+=1;else ans+=2;
        return ans;
    }
};