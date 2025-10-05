class Solution {
public:
    bool solve(string& s,unordered_map<string,int>& mp,int& tar, int&n ,int& k){
        if(s.size()==tar+n-1)return true;
        string temp=s.substr(s.size()-n+1);
        for(int i=0;i<k;i++){
            char c='0'+i;
            if(!mp.count(temp+c)){
                mp[temp+c]=1;
                s+=c;
                if(solve(s,mp,tar,n,k))return true;
                mp.erase(temp+c);
                s.pop_back();
            }
        }
        return false;
    }
    string crackSafe(int n, int k) {
        string s(n,'0');
        unordered_map<string,int> mp;
        mp[s]=1;
        int tar=pow(k,n);
        solve(s,mp,tar,n,k);
        return s;
    }
};