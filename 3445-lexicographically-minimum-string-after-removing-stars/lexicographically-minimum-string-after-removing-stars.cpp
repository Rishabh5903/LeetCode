class Solution {
public:
    string clearStars(string s) {
        priority_queue<pair<char,int>,vector<pair<char,int>>, greater<pair<char,int>>> pq;
        vector<int> ind;
        for(int i=0;i<s.size();i++){
            if(s[i]!='*'){
                pq.push({s[i],-i});
            }
            else{
                ind.push_back(i);
                ind.push_back(-pq.top().second);pq.pop();
            }
        }
        sort(ind.begin(),ind.end());
        string ans="";int j=0;
        for(int i=0;i<s.size();i++){
            if(j<ind.size() && i==ind[j]){j++;continue;}
            else ans+=s[i];
        }
        return ans;
    }
};