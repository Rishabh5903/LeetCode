class Solution {
public:
    string makeFancyString(string s) {
        int temp=1;
    string ans="";ans+=s[0];
        for (int i=1;i<s.size();i++){
            if(s[i]!=s[i-1]){ans+=s[i];temp=1;}
            else if(temp<2){ans+=s[i];temp++;}
        }
        return ans;
    }
};