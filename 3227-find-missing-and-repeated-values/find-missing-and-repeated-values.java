class Solution {
    public int[] findMissingAndRepeatedValues(int[][] grid) {int n=grid.length;
        int [] ans = new int[2];
        int [] fr = new int[n*n+1];
        for(int i=0;i<n;i++){
            for(int j = 0;j < n; j++)fr[grid[i][j]]++;
        }
        for(int i=1;i<=n*n;i++){
            if(fr[i] == 2)ans[0] = i;
            if(fr[i] == 0)ans[1] = i;
        }
        return ans;

    }
}