class Solution {
    public int findLHS(int[] nums) {
        HashMap<Integer,Integer> mp = new HashMap<>();
        for(int i:nums)mp.put(i,mp.getOrDefault(i,0)+1);
        List<Map.Entry<Integer, Integer>> v = new ArrayList<>(mp.entrySet());
        v.sort(Map.Entry.comparingByKey());
        int ans=0;
        for(int i=0;i<v.size()-1;i++){
            if(v.get(i).getKey() == v.get(i+1).getKey()-1)ans=Math.max(ans,v.get(i).getValue()+v.get(i+1).getValue());
        }
        return ans;


    }
}