class Solution {
public:
    int calculate(string s) {int n=s.size();
        stack<char> st;int neg=0;
        string num="0";int ans=0;char prev='+';
        for(int i=0;i<n;i++){char c=s[i];
            if(!isdigit(c)){ans+=((neg%2)?-1:1)*((prev=='+')?1:-1)*stoi(num);num="0";}
            if(c=='+'){prev='+';
                if(s[i+1]=='(' || (s[i+1]==' ' && s[i+2]=='(')){st.push(c);}
            }
            else if(c=='-'){prev='-';if(s[i+1]=='(' || (s[i+1]==' ' && s[i+2]=='(')){st.push(c);neg++;prev='+';}}
            if(c==')' && st.size()){if(st.top()=='-')neg--;st.pop();}
            if(isdigit(c))num+=c;

        }
        ans+=((neg%2)?-1:1)*((prev=='+')?1:-1)*stoi(num);
        return ans;
    }
};