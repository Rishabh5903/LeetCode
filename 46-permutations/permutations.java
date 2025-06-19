class Solution {
    public void solve(List<List<Integer>> ans,int [] nums,List<Integer> temp){
        if(temp.size()==nums.length){ans.add(temp);return;}
        for(int i=0;i<nums.length;i++){
            if(temp.contains(nums[i])==false){
                
                temp.add(nums[i]);
                List<Integer> temp1 = new ArrayList<>(temp);
                solve(ans,nums,temp1);
                temp.remove(temp.size()-1);
            }
        }
    }
    public List<List<Integer>> permute(int[] nums) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> temp = new ArrayList<>();

        solve(ans,nums,temp);
        return ans;
    }
}