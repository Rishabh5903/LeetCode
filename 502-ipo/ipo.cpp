class Solution {
public:
    int findMaximizedCapital(int k, int w, vector<int>& profits, vector<int>& capital) {
        priority_queue<int> pq;int n=profits.size();
        vector<pair<int,int>> v;
        for(int i=0;i<profits.size();i++){
            v.push_back({capital[i],profits[i]});
        }
        sort(v.begin(),v.end());
        int i=0;
        while(i<n && v[i].first<=w){
            pq.push(v[i].second);i++;
        }
        int ans=w,cnt=0;
        while(pq.size() && cnt<k){
            ans+=pq.top();w+=pq.top();pq.pop();
            while(i<n && v[i].first<=w){
                pq.push(v[i].second);i++;
            }
            cnt++;
        }
        return ans;
    }
};