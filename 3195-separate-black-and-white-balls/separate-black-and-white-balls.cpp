class Solution {
public:
    long long minimumSteps(string s) {
        int ones=0;
        long long ans=0;
        for(char i:s){
            if(i=='1')ones++;
            else ans+=ones;
        }
        return ans;
    }
};