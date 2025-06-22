class Solution {
    public String[] divideString(String s, int k, char fill) {
        StringBuilder sb = new StringBuilder(s);
        
        int n = sb.length();
        if(n%k != 0){
            for(int i=0;i<k-n%k;i++)sb.append(fill);
        }
        String [] ans = new String[sb.length()/k];
        s= sb.toString();
        for(int i=0;i<sb.length();i+=k){
            ans[i/k] = s.substring(i,i+k);
        }
        return ans;
    }
}