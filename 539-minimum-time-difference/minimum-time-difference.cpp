class Solution {
public:
    int findMinDifference(vector<string>& time) {
        vector<int> v;
        for(string& s:time){
            int h = stoi(s.substr(0,2));
            int m = stoi(s.substr(3));
            v.push_back(h*60+m);
            v.push_back(-((24-h-1)*60+60-m));

        }
        sort(v.begin(),v.end());
        int ans=INT_MAX;
        for(int i=1;i<v.size();i++){
            ans=min(ans,v[i]-v[i-1]);
        }
        return ans;
    }
};