class Solution {
public:
    int numSteps(string s) {
        int temp=0,ans=0;
        for(int i=s.size()-1;i>=0;i--){
            if(s[i]=='1')temp++;
            else{
                if(temp){
                    ans+=temp+1;temp=1;

                }
                else ans++;
            }
        }                if(temp>1){
                    ans+=temp+1;temp=1;

                }
                return ans;
    }
};