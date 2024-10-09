class Solution {
public:
    int minAddToMakeValid(string st) {
        stack<int> s;int ans=0;
        for(char i:st){
            if(i=='(')s.push(1);
            else {
                if(s.size())s.pop();
                else ans++;
            };
            // if(cnt<)
        }
        ans+=s.size();
        return ans;
    }
};