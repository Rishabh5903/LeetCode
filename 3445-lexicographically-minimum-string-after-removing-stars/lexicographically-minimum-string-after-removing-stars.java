class Solution {
    public String clearStars(String s) {
        int n = s.length();
        PriorityQueue<Character> pq = new PriorityQueue<>();
        Map<Character,ArrayList<Integer>> mp=new HashMap<>();
        boolean[] keep = new boolean[n];
        Arrays.fill(keep,true);
        for(int i=0;i<n;i++){
            char c = s.charAt(i);
            if(c == '*'){
                char temp = pq.poll();
                keep[i] = false;
                keep[mp.get(temp).remove(mp.get(temp).size()-1)] = false;
            }
            else{
                pq.add(c);
                mp.putIfAbsent(c,new ArrayList<Integer>());
                mp.get(c).add(i);
            }
        }

        StringBuilder ans = new StringBuilder();
        for (int i = 0; i < n; i++){
            if (keep[i]) {
                ans.append(s.charAt(i));
            }
        }
        return ans.toString();
        
    }
}