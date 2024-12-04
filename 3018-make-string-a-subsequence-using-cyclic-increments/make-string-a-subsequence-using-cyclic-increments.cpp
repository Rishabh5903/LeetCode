class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        string s="abcdefghijklmnopqrstuvwxyz";
        int i=0,j=0;
        while(i<str1.size() && j<str2.size()){
            if(str1[i]==str2[j] || (s[(str1[i]-'a'+1)%26]==str2[j])){j++;}
            i++;
        }
        return j==str2.size();
    }
};