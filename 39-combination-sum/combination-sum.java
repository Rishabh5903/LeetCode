class Solution {
    private void solve(List<List<Integer>> ans,int[] candidates, int target,int j, List<Integer> curr, int tot){
        if(tot==target){
            List<Integer> temp = new ArrayList<>(curr);ans.add(temp);return;
        }
        else if(tot>target || j>=candidates.length)return;
        for(int i=j;i<candidates.length;i++){
            curr.add(candidates[i]);tot+=candidates[i];solve(ans,candidates,target,i,curr,tot);
            curr.remove(curr.size()-1);tot-=candidates[i];
        }
        // solve(ans,candidates,target,j+1,curr,tot);
    }
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        List<List<Integer>> ans = new ArrayList<>();
        List<Integer> curr = new ArrayList<>();
        int tot=0;
        solve(ans,candidates,target,0,curr,tot);
        return ans;
    }
}