class Solution {
public:
int mapped(int i,vector<int>& mapping){
    string temp=to_string(i);
    string ans="";
    for(char i:temp){
        ans+=to_string(mapping[i-'0']);
    }return stoi(ans);
}
    vector<int> sortJumbled(vector<int>& mapping, vector<int>& nums) {
        vector<pair<int,int>> v;
        for(int i=0;i<nums.size();i++){
            v.push_back({mapped(nums[i],mapping),i});
        }sort(v.begin(),v.end());
        vector<int> ans;
        for(auto i:v)ans.push_back(nums[i.second]);return ans;
    }
};