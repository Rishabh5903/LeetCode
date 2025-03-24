class Solution {
    public int countDays(int days, int[][] meetings) {int n=meetings.length;
        Arrays.sort(meetings, (row1, row2) -> {
            for (int i = 0; i < Math.min(row1.length, row2.length); i++) {
                if (row1[i] != row2[i]) {
                    return Integer.compare(row1[i], row2[i]);
                }
            }
            return Integer.compare(row1.length, row2.length);
        });
        int ans=0,finish=meetings[0][1];
        for(int i=1;i<n;i++){
            if(meetings[i][0]>(finish+1))ans+=meetings[i][0]-finish-1;
            finish=Math.max(finish,meetings[i][1]);
        }
        ans+=meetings[0][0]-1+days-finish;
        return ans;
    }
}