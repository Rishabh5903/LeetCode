class Solution {
public:
    bool ispalindrome(int i, int j, string& s){
        if(i>j)return false;
        while(i<j){
            if(!(s[i]==s[j])) return false;
            i++; j--;
        }
        return true;
    }
    string longestPalindrome(string s) {
        int maxo=0;
        string ans = "";
        for(int i=0; i<s.size(); i++){
            for(int j=i; j<s.size(); j++){
                if(ispalindrome(i,j,s)){
                    if(j-i+1 > maxo){
                        maxo = j-i+1;
                        ans= s.substr(i,maxo);
                    }
                }
            }
        }
        return ans;
    }
};