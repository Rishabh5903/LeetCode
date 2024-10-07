class Solution {
public:
    int minLength(string s) {
        stack<char> st;

        for (char i:s){
            if(!st.size()){st.push(i);continue;}
            if(i=='B'){
                if(st.top()=='A')st.pop();
                else st.push(i);
            }
            else if(i=='D'){
                if(st.top()=='C')st.pop();
                else st.push(i);
            }
            else st.push(i);
        }return st.size();
    }
};