class Solution {
public:
    int minimumDeletions(string s) {
        vector<int> v;
        int n1=0,n2=0;
        for(char i:s)if(i=='a')n2++;
        int ans=INT_MAX;
        for(int i=0;i<s.size()-1;i++){
            if(s[i]=='a')n2--;
            else n1++;
            if(s[i]=='b' && s[i+1]=='a'){
                if(v.size()==0)ans=min(ans,n2);
                else ans=min(ans,v.back()+n2);
                v.push_back(n1);
            }
        }
        if(v.size())
        ans=min(ans,v.back());
        return (ans==INT_MAX ? 0 : ans);
    }
};