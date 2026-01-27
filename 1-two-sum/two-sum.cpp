class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        unordered_map<int,vector<int>> mp;
        vector<int> ans;
        for(int i=0;i<nums.size();i++)mp[nums[i]].push_back(i);
        for(int i:nums){
            
            if(mp[target-i].size() > ((target != 2*i) ? 0 : 1)){ans = {mp[i].back(),((target != 2*i) ? mp[target-i].back() : mp[target-i][0])};break;}
        }
        return ans;
    }
};