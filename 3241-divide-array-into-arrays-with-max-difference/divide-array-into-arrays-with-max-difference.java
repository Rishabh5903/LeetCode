class Solution {
    public int[][] divideArray(int[] nums, int k) {
        Arrays.sort(nums);
        int n = nums.length;
        int[][] ans= new int[n/3][3];
        int [][] empty = new int[0][0];
        for(int i=0;i<n;i++){
            if(i%3==0) ans[i/3][0]=nums[i];
            else if(i%3==1) {ans[i/3][1]=nums[i];if(ans[i/3][1]-ans[i/3][0]>k)return empty;}
            else if(i%3==2) {ans[i/3][2]=nums[i];if(ans[i/3][2]-ans[i/3][0]>k)return empty;}
        }
        return ans;
    }
}