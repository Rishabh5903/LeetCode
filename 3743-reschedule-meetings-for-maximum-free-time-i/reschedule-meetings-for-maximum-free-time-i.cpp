class Solution {
public:
    int maxFreeTime(int eventTime, int k, vector<int>& startTime, vector<int>& endTime) {
        int n = startTime.size();
        vector<int> gaps={0};
        gaps.push_back(startTime[0]);
        for(int i=0;i<n-1;i++){
            gaps.push_back(startTime[i+1]-endTime[i]);
        }
        gaps.push_back(eventTime-endTime[n-1]);
        int ans=0;
        if(gaps.size()<k+2)return gaps.back();
        for(int i=1;i<gaps.size();i++)gaps[i]+=gaps[i-1];
        for(int i=k+1;i<gaps.size();i++){
            ans=max(ans,gaps[i]-gaps[i-k-1]);
        }
        return ans;
    }
};