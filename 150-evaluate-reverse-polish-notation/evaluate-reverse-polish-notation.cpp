class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        stack<int> st;
        int temp;
        for(string s:tokens){
            if(s=="+"){
                temp=st.top(); st.pop();
                st.top() += temp;
            }
            else if(s == "-"){
                temp=st.top(); st.pop();
                st.top() -= temp;
            }
            else if(s == "*"){
                temp=st.top(); st.pop();
                st.top() *= temp;
            }
            else if(s == "/"){
                temp=st.top(); st.pop();
                st.top() /= temp;
            }
            else st.push(stoi(s));
        }
        return st.top();
    }
};
