class Solution {
public:
    bool canConstruct(string s, int k) {
        int n=s.size();if(k>n)return false;
        vector<int> fr(26,0);
        for(char c:s)fr[c-'a']++;
        int cnt=0;
        for(int i:fr)if(i%2)cnt++;
        if(cnt>k)return false;return true;
    }
};