class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        int n=position.size();
        vector<pair<int,double>> v;
        vector<double> maxo(n,0);
        for(int i=0;i<n;i++){
            double time=(target-position[i])/(double)(speed[i]);
            v.push_back({position[i],time});
        }
        sort(v.begin(),v.end());
        maxo.back()=v.back().second;
        for(int i=n-2;i>=0;i--){
            maxo[i]=max((double)maxo[i+1],v[i].second);
        }
        int ans=0;
        for(int i=0;i<n-1;i++){
            if(maxo[i+1]<v[i].second)ans++;
        }
        ans++;
        return ans;
    }
};