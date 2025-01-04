class Solution {
public:
    int countPalindromicSubsequence(string s) {int n=s.size();
        int ans=0;set<char> st;int l,r;
        for(int i=0;i<26;i++){
        l=0,r=n-1;st.clear();
        while(l<r && ((s[l]-'a')!=i))l++;
        while(r>l && ((s[r]-'a')!=i))r--;
        if(r<=l+1)continue;
        for(int j=l+1;j<r;j++){
            st.insert(s[j]);
        }
        ans+=st.size();
        }
        return ans;

    }
};