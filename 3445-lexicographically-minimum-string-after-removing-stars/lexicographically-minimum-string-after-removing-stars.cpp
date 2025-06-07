class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>, greater<pair<char,int>>> pq;
        vector<bool> keep(s.size(),true);
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                pq.push({s[i],-i});
            }
            else{
                keep[i]=0;
                keep[-pq.top().second]=0;pq.pop();
            }
        }
        // sort(ind.begin(),ind.end());
        string ans="";int j=0;
        for(int i=0;i<s.size();i++){
            if(keep[i])ans+=s[i];
        }
        return ans;
    }
};