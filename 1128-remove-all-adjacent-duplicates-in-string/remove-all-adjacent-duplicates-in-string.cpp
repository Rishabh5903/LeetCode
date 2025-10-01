class Solution {
public:
    string removeDuplicates(string s) {
        stack<char> st;
        for(char c:s){
            if(st.size() && st.top()==c)st.pop();
            else st.push(c);
        }
        string ans="";
        while(st.size()){ans+=st.top();st.pop();}
        reverse(ans.begin(),ans.end());
        return ans;
    }
};