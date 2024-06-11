class Solution {
public:
    vector<int> relativeSortArray(vector<int>& arr1, vector<int>& arr2) {
        unordered_map<int,int> mp;
        for(int i:arr1)mp[i]++;
        vector<int> ans;vector<int> temp;
        for(int i:arr2){
            for(int j=0;j<mp[i];j++){ans.push_back(i);}mp[i]=0;
        }for(auto i:mp)if(i.second>0)for(int j=0;j<i.second;j++){temp.push_back(i.first);}
        sort(temp.begin(),temp.end());for(int i:temp)ans.push_back(i);return ans;

    }
};