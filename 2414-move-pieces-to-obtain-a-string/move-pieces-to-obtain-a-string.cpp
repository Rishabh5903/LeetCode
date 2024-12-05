class Solution {
public:
    bool canChange(string a, string b) {
        int n=a.size();
        stack<char> s;
        for(int i=0;i<n;i++){
            if(a[i]!=b[i]){
                if((a[i]=='_' && b[i]=='L') || (a[i]=='R' && b[i]=='_')){
                    if(s.empty() || s.top()==a[i])s.push(a[i]);
                    else return false;
                }
                else if((a[i]=='_' && b[i]=='R') || (a[i]=='L' && b[i]=='_')){
                    if(s.empty() || (a[i]=='L' && s.top()!='_') || (a[i]=='_' && s.top()!='R'))return false;
                    else s.pop();
                }
                else return false;
            }
            else if(!s.empty() && ((s.top()=='_' && a[i]=='R') || (s.top()=='R' && a[i]=='L')))return false;
        }
        
        return !s.size();
    }
};