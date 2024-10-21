class Solution {
public:
    int maxUniqueSplit(string s) {
        int ans=0;
        for(int i=0;i<pow(2,s.size());i++){
            set<string> x;
            string temp="";
            for(int j=s.size()-1;j>=0;j--){
                if(i & (1<<j)){
                    if(!(temp==""))x.insert(temp);
                    temp=s[j];
                }
                else temp+=s[j];
            }
            x.insert(temp);
            ans=max(ans,(int)x.size());
        }
        return ans;
    }
};