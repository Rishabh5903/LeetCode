class Solution {
public:
    long long maximumImportance(int n, vector<vector<int>>& roads) {
        map<int,int> mp;
        for (auto i:roads){
            mp[i[0]]++;mp[i[1]]++;
        }
        vector<int> v;
        for (auto i:mp)v.push_back(i.second);sort(v.rbegin(),v.rend());
        long long ans=0;long long temp=n;
        for(long long i:v){ans+=temp*i;temp--;}return ans;
    }
};