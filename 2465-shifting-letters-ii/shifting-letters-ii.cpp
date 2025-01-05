class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {int n=s.size();
        vector<int> change(n+1,0);
        for(auto i:shifts){
            if(i[2]==0){change[i[0]]--;change[i[1]+1]++;}
            else {change[i[0]]++;change[i[1]+1]--;}
        }
        for(int i=1;i<=n;i++)change[i]+=change[i-1];
        for(int i=0;i<n;i++)s[i]='a'+(s[i]-'a'+((change[i]%26)+26)%26)%26;
        return s;

    }
};