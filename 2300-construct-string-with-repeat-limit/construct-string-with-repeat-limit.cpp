class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> fr(26,0);
        for(char c:s)fr[c-'a']++;
        string ans="";
        int i=24,j=25;int temp=0;
        while(i>=0 || j>=0){
            while(j>=0 && fr[j]==0){j--;temp=0;}
            while(i>=0 && (fr[i]==0 || i>=j))i--;
            if(temp<repeatLimit){
                if(j>=0){ans+='a'+j;temp++;fr[j]--;}else break;
            }
            else{
                if(i>=0){ans+='a'+i;temp=0;fr[i]--;}
                else break;
            }
            
        }
        return ans;

    }
};