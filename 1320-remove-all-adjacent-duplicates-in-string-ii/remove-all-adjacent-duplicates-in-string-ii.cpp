class Solution {
public:
    string removeDuplicates(string s, int k) {
        stack<pair<int,int>> st;
        // st.push({s[0]-'a',1});
        for(int i=0;i<s.size();i++){
                while(st.size() && st.top().second>=k)st.top().second-=k;
                while(st.size() && st.top().second==0)st.pop();
            if(st.size()){

                if(s[i]-'a'==st.top().first){st.top().second++;}
                else st.push({s[i]-'a',1});
            }
            else {st.push({s[i]-'a',1});}
            
        }
                        while(st.size() && st.top().second>=k)st.top().second-=k;
                while(st.size() && st.top().second==0)st.pop();
        string ans="";
        while(st.size()){
            auto p=st.top();st.pop();
            for(int i=0;i<p.second;i++)ans+=('a'+p.first);
        }
        reverse(ans.begin(),ans.end());
        return ans;
    }
};