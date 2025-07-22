class Solution {
public:
    int maximumUniqueSubarray(vector<int>& nums) {
        int ans=nums[0];
        int temp=nums[0];
        unordered_map<int,int> mp;
        mp[nums[0]]=0;
        int l=0,r=1;
        while(r<nums.size()){
            if(mp.find(nums[r])!=mp.end()){
                ans=max(ans,temp);
                while(l<=mp[nums[r]]){temp-=nums[l];mp.erase(nums[l]);l++;}

            }
            mp[nums[r]]=r;
            temp+=nums[r];
            r++;
        }
        ans=max(ans,temp);
        return ans;
    }
};