class Solution {
    public List<Integer> partitionLabels(String s) {int n=s.length();
        int[] lis=new int[26];for(int i=0;i<=25;i++)lis[i]=-1;
        List<Integer> ans=new ArrayList<>();
        for(int i=n-1;i>=0;i--){
            if(lis[s.charAt(i)-'a']==-1)lis[s.charAt(i)-'a']=i;
        }
        int maxo=-1,cnt=0;
        for(int i=0;i<n;i++){
            maxo=Math.max(maxo,lis[s.charAt(i)-'a']);cnt++;
            if(i==maxo){ans.add(cnt);cnt=0;}
        }
        return ans;

    }
}