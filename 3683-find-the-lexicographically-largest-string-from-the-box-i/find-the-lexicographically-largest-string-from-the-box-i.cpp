class Solution {
public:
    string answerString(string word, int n) {
        if(n==1)return word;
        int m=word.size();
        // char c='a';
        // for(char ch:word)c=max(c,ch);
        string ans="";string temp="";char prev='a';
        for(int i=0;i<m;i++){
            prev=max(prev,word[i]);
            if(word[i]<prev)continue;temp="";
            for(int j=i;j<min(m,i+m-n+1);j++)temp+=word[j];
            ans=max(ans,temp);
        }
        return ans;
        
    }
};