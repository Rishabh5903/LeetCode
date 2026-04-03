class Solution {
public:
    vector<int> f;
    int fact(int n){
        if(f[n]!=-1) return f[n];
        int ans=1;
        for(int i=2;i<=n;i++)ans*=i;
        return f[n]=ans;
    }
    string getPermutation(int n, int k) {
        f.resize(10,-1);
        string ans="";
        vector<int> s;
        for(int i=1;i<=n;i++)s.push_back(i);
        int temp=n-1;
        while(k>1){
            int curr = (k + fact(temp) -1)/fact(temp);
            ans+='0'+s[curr-1];
            s.erase(s.begin() + curr-1);
            k-=(curr-1)*fact(temp);
            temp--;
            
        }
        for(int i:s)ans+='0'+i;
        return ans;
    }
};