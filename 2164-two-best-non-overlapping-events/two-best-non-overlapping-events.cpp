class Solution {
public:
    int maxTwoEvents(vector<vector<int>>& events) {
         sort(events.begin(),events.end());
        vector<int> start,maxo(events.size(),0);
        for(int i=events.size()-1;i>=0;i--){
            start.push_back(events[i][0]);
            if(i<events.size()-1)
            maxo[i]=max(maxo[i+1],events[i][2]);
            else maxo[i]=events[i][2];
        }
        sort(start.begin(),start.end());
        int ans=0;
        for(int i=0;i<start.size();i++){
            int ind=upper_bound(start.begin(),start.end(),events[i][1])-start.begin();
            if(ind<start.size()){
                ans=max(ans,events[i][2]+maxo[ind]);
            }
            else ans=max(ans,events[i][2]);
        }
        return ans;
    }
};