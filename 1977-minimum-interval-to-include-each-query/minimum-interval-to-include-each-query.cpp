class Solution {
public:
    vector<int> minInterval(vector<vector<int>>& intervals, vector<int>& queries) {
        vector<int> Q=queries, ans;
        unordered_map<int,int> mp;
        sort(intervals.begin(),intervals.end());
        sort(Q.begin(),Q.end());
        priority_queue<vector<int>> pq;
        int i=0,n=intervals.size();
        for(int q:Q){
            while(i<n && intervals[i][0]<=q){
                int l=intervals[i][0],r=intervals[i++][1];
                pq.push({l-r-1,r});
            }
            while(pq.size() && pq.top()[1]<q)pq.pop();
            mp[q]=pq.size()? -pq.top()[0] : -1;
        }
        for(int q:queries)ans.push_back(mp[q]);
        return ans;
    }
};