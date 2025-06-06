class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int ans=1,l=0,used=0;
        for(int r=0;r<nums.size();r++){
            while((used & nums[r])!=0){used^=nums[l];l++;}
            used|=nums[r];
            ans=max(ans,r-l+1);

        }
        return ans;
    }
};