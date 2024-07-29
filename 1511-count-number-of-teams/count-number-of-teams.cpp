class Solution {
public:
    int numTeams(vector<int>& rating) {
        vector<pair<int,int>> v;
        for (int i=0;i<rating.size();i++){
            v.push_back({rating[i],i});
        }sort(v.begin(),v.end());
        int ans=0;
        for(int i=0;i<v.size();i++){
            int l1=0,r1=0,l2=0,r2=0;
            for(int j=0;j<i;j++){
                if(v[j].second<v[i].second)l1++;
                else r2++;
            }
            for(int j=i+1;j<v.size();j++){
                if(v[j].second>v[i].second)r1++;
                else l2++;
            }ans+=l1*r1+l2*r2;
        }return ans;
    }
};