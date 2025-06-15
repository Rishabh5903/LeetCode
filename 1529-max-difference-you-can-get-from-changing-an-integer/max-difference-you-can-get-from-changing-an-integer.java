class Solution {
    public int maxDiff(int num) {
        String s = Integer.toString(num);
        StringBuilder sb = new StringBuilder(s);
        char rep='.';
        for(int i=0;i<s.length();i++){
            if(rep=='.' && sb.charAt(i)!='9')rep=sb.charAt(i);
            if(sb.charAt(i)==rep)sb.setCharAt(i,'9');
        }
        s = sb.toString();
        int a = Integer.parseInt(s);
        s = Integer.toString(num);
        sb.replace(0, sb.length(), s);
        rep = '.';
        char change;
        if( sb.charAt(0) != '1'){rep = sb.charAt(0);change='1'; sb.setCharAt(0, '1');}else change = '0';
        
        for(int i = 1; i < s.length(); i++){
            if(rep == '.' && sb.charAt(i) != '1' && sb.charAt(i) != '0')rep = sb.charAt(i);
            if( sb.charAt(i) == rep ) sb.setCharAt(i, change);
        }
        s = sb.toString();
        int b = Integer.parseInt(s);
        return a-b;
    }
}