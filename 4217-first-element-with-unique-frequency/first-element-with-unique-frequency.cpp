class Solution {
public:
    int firstUniqueFreq(vector<int>& nums) {
        unordered_map<int,int> mp;
        unordered_map<int,int> fr;
        for(int i=nums.size()-1;i>=0;i--){
            if(fr[mp[nums[i]]])fr[mp[nums[i]]]--;
            mp[nums[i]]++;
            fr[mp[nums[i]]]++;
        }
        for(int i=0;i<nums.size();i++){
            if(fr[mp[nums[i]]]==1)return nums[i];
        }
        return -1;
    }
};