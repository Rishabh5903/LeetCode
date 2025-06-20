class Solution {
    public int maxDistance(String s, int k) {
        int ans=0;
        int a=0,b=0,c=0,d=0;
        // int a1,b1,c1,d1;
        for(int i=0;i<s.length();i++){
            if(s.charAt(i)=='N')a++;else if(s.charAt(i)=='S')b++;
            if(s.charAt(i)=='E')c++;else if(s.charAt(i)=='W')d++;
            int temp=Math.max(a,b)+Math.max(c,d)-Math.min(a,b)-Math.min(c,d)+2*Math.max(0,Math.min(Math.min(a,b)+Math.min(c,d),k));
            ans=Math.max(ans,temp);

        }
        return ans;
    }
}