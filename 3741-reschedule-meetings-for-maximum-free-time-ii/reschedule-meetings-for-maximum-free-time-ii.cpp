class Solution {
public:
    int maxFreeTime(int eventTime, vector<int>& startTime, vector<int>& endTime) {
        vector<int> gaps;
        
        gaps.push_back(startTime[0]);
        for(int i=0;i<startTime.size()-1;i++){
            gaps.push_back(startTime[i+1]-endTime[i]);
        }
        gaps.push_back(eventTime-endTime.back());
        int n=gaps.size();
        vector<int> left(n),right(n);
        left[0]=gaps[0];
        right[n-1]=gaps[n-1];
        for(int i=1;i<gaps.size();i++)left[i]=max(left[i-1],gaps[i]);
        for(int i=n-2;i>=0;i--)right[i]=max(right[i+1],gaps[i]);
        int ans=0;
        for(int i=0;i<startTime.size();i++){
            int l=endTime[i]-startTime[i];
            ans=max(ans,gaps[i]+gaps[i+1]+(((i?(left[i-1]>=l):0) || ((i<gaps.size()-2) ? (right[i+2]>=l) : 0)) ? l : 0));
        }
        return ans;
    }
};