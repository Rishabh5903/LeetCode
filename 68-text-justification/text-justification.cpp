class Solution {
public:
    vector<string> fullJustify(vector<string>& words, int maxWidth) {
        vector<string> ans;
        vector<string> temp;
        int len=0;
        for (string s:words){
            if(len+s.size()<=maxWidth){
                len+=s.size()+1;temp.push_back(s);
            }
            else{
                len--;
                if(temp.size()==1){
                    ans.push_back(temp[0]+string(maxWidth-temp[0].size(),' '));
                }
                else{
                int k=temp.size()-1,tot=maxWidth-len+k;
                int spaces=(tot)/(k);
                for(int i=0;i<tot%k;i++){
                    temp[i]+=string(spaces+1,' ');
                }
                for(int i=tot%k;i<temp.size()-1;i++)temp[i]+=string(spaces,' ');
                ans.push_back(accumulate(temp.begin(),temp.end(),string()));}
                temp={s};len=s.size()+1;

            }
        }
        string last="";for(string s:temp)last+=s+(last.size()+s.size()+1<=maxWidth?" ":"");
        last+=string(maxWidth-last.size(),' ');
        ans.push_back(last);
        return ans;
    }
};