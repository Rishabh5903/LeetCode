class Solution {
public:
    bool canTransform(string start, string result) {
        int ans=1;
        int i=0,j=0;
        stack<char> s;
        while(i<start.size()){
            if(start[i]!=result[j]){
                if(start[i]=='R' && result[j]=='X'){
                    if(!s.size() || s.top()=='R')s.push('R');
                    else return false;
                }
                else if(start[i]=='X' && result[j]=='L'){
                    if(!s.size() || s.top()=='L')s.push('L');
                    else return false;
                }
                else if(start[i]=='X' && result[j]=='R'){
                    if(s.size() && s.top()=='R')s.pop();
                    else return false;
                }
                else if(start[i]=='L' && result[j]=='X'){
                    if(s.size() && s.top()=='L')s.pop();
                    else return false;
                }
                else return false;
                
            }
            else if(start[i]!='X' && s.size() && start[i]!=s.top())return false;
            i++;j++;
        }
        return (s.size()==0);

    }
};