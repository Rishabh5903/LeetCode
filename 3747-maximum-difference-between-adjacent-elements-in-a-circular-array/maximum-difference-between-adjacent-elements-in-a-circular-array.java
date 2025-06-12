class Solution {
    public int maxAdjacentDistance(int[] nums) {
        int ans=0;
        int n=nums.length;
        for(int i=0;i<n;i++){
            ans=Math.max(ans,Math.abs(nums[i%n]-nums[(i+1)%n]));
        }
        return ans;
    }
}