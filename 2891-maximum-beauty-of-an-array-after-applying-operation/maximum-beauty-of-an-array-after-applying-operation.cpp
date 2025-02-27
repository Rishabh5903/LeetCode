class Solution {
public:
    int maximumBeauty(vector<int>& nums, int k) {
        sort(nums.begin(),nums.end());
        int ans=0;int ind=0;
        for (int i=0;i<nums.size();i++){
            while(ind<nums.size() && nums[ind]<=(nums[i]+2*k))ind++;
            ans=max(ans,ind-i);
        }
        return ans;
    }
};