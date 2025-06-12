class Solution {
public:
    unordered_map<string,bool> mp;
    bool isScramble(string s1, string s2) {
        int n=s1.size();if(s2.size()!=n)return false;if(s1==s2)return true;if(s1.size()==1)return false;
        // bool b1=false,b2=false;
        string curr=s1+","+s2;
        if(mp.find(curr)!=mp.end())return mp[curr];
        string temp1 = s1, temp2 = s2;
        sort(temp1.begin(), temp1.end());
        sort(temp2.begin(), temp2.end());
        if (temp1 != temp2) return mp[curr] = false;
        for(int i=1;i<n;i++){
            if(isScramble(s1.substr(0,i),s2.substr(0,i)) && isScramble(s1.substr(i),s2.substr(i)))return mp[curr]=true;
            if(isScramble(s1.substr(0,i),s2.substr(n-i)) && isScramble(s1.substr(i),s2.substr(0,n-i)))return mp[curr]=true;
            
        }
        return mp[curr]=false;
    }
};