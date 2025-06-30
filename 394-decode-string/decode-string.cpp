class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        string curr="",num="0";
        for(char c:s){
            if(c=='['){
                st.push(curr);st.push(num);
                curr="";num="0";
            }
            else if(c==']'){
                string num1=st.top();st.pop();
                string prev=st.top();st.pop();
                // curr=prev;
                string temp=curr;
                int n;n=stoi(num1);
                for(int i=0;i<n-1;i++)curr+=temp;
                curr=prev+curr;
            }
            else if(isdigit(c))num+=c;
            else curr+=c;
        }
        return curr;
    }
};