class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int ans=0,prev=0;
        for(int i=1;i<nums.size();i++){
            if(nums[i]>nums[i-1]){
                ans+=(prev==1);prev=2;
            }
            else if(nums[i]<nums[i-1]){
                ans+=(prev==2);prev=1;
            }
        }
        return ans;
    }
};