class Solution {
    public int partitionArray(int[] nums, int k) {
        Arrays.sort(nums);
        int mino=nums[0];
        int ans=1;
        for(int i=1;i<nums.length;i++){
            if(nums[i]-mino>k){mino=nums[i];ans++;}
        }
        return ans;
    }
}