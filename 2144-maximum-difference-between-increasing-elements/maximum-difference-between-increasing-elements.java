class Solution {
    public int maximumDifference(int[] nums) {
        int n=nums.length;
        int[] maxo=new int[n];
        maxo[n-1]=nums[n-1];
        for(int i=n-2; i >= 0; i--){
            maxo[i] = Math.max(nums[i],maxo[i+1]);
        }
        int ans = Integer.MIN_VALUE;
        for(int i=n-2;i>=0;i--)ans=Math.max(ans,maxo[i+1]-nums[i]);
        return (ans<=0 ? -1 : ans);
    }
}