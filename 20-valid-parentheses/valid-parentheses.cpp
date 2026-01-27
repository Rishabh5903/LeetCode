class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        unordered_map<char,char> mp;
        mp[')']='(';
        mp[']']='[';
        mp['}']='{';
        for(char c:s){
            if(c==')' || c==']' || c=='}'){
                if(st.size() && st.top()==mp[c])st.pop();
                else return false;
            }
            else st.push(c);
        }
        return st.size() ? false : true;
    }
};