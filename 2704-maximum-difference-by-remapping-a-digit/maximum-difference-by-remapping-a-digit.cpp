class Solution {
public:
    int minMaxDifference(int num) {
        string s=to_string(num);
        char rep='.';
        for(int i=0;i<s.size();i++){
            if(rep=='.' && s[i]!='9'){rep=s[i];}
            if(s[i]==rep)s[i]='9';
        }
        int maxo=stoi(s);
        s=to_string(num);
        rep='.';
        for(int i=0;i<s.size();i++){
            if(rep=='.' && s[i]!='0'){rep=s[i];}
            if(s[i]==rep)s[i]='0';
        }
        int mino=stoi(s);
        return maxo-mino;
    }
};