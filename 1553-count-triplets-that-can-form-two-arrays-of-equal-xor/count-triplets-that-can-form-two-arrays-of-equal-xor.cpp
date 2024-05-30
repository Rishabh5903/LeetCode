class Solution {
public:
    int solve(vector<int> v){
        int n=v.size();
        int temp=0,num=n-1;
        for(int i=n-1;i>=0;i--){
            temp+=num*(v[i]);num-=2;
        }return temp-(n*(n-1))/2;
    }
    int countTriplets(vector<int>& arr) {
        vector<int> v={0};int ans=0;
        for(int i:arr)v.push_back(v.back()^i);
        unordered_map<int,vector<int>> mp;mp[0].push_back(0);
        for(int i=1;i<v.size();i++){
            mp[v[i]].push_back(i);
        }
        for(auto i:mp){
            ans+=solve(i.second);
        }
        return ans;
    }
};