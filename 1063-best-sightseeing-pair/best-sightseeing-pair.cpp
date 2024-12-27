class Solution {
public:
    int maxScoreSightseeingPair(vector<int>& values) {
        int maxo=values[0],ans=0;
        for(int i=1;i<values.size();i++){
            ans=max(ans,maxo+values[i]-i);
            maxo=max(maxo,values[i]+i);
        }
        return ans;
    }
};