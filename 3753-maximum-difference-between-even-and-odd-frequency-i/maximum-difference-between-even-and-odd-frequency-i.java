class Solution {
    public int maxDifference(String s) {
        int n=s.length(), maxo=0, mino=n;
        int[] freq=new int[26];
        Arrays.fill(freq,0);
        for(int i=0;i<n;i++)freq[s.charAt(i)-'a']++;
        for(int i=0;i<26;i++)if(freq[i]%2==1)maxo=Math.max(maxo,freq[i]);else if(freq[i]>0) mino=Math.min(mino,freq[i]);
        return maxo-mino;
    }
}