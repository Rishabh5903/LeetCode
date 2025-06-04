class Solution {
public:
    string answerString(string word, int n) {
        if(n==1)return word;
        int m=word.size();
        // char c='a';
        // for(char ch:word)c=max(c,ch);
        string ans="";string temp="";
        for(int i=0;i<m;i++){
            temp="";
            for(int j=i;j<min(m,i+m-n+1);j++)temp+=word[j];
            ans=max(ans,temp);
        }
        return ans;
        
    }
};