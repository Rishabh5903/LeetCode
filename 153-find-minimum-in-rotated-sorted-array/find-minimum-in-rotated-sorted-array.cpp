class Solution {
public:
    int findMin(vector<int>& nums) {
        if(nums[0]<=nums.back())return nums[0];
        int l=0,r=nums.size()-1,mid;
        while(l<=r){
            mid=l+(r-l)/2;
            if(nums.back()>=nums[mid])r=mid-1;
            else l=mid+1;
        }
        return nums[r+1];
    }
};