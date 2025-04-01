class Solution {
    public long mostPoints(int[][] questions) {int n=questions.length;
        long[] maxo=new long[n];maxo[n-1]=questions[n-1][0];
        for(int i=n-2;i>=0;i--){
            maxo[i]=Math.max(maxo[i+1],questions[i][0]+((i+questions[i][1]+1 <n)?maxo[i+questions[i][1]+1]:0));
        }
        return maxo[0];
    }
}