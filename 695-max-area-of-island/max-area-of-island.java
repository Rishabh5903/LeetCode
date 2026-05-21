class Solution {

    public void dfs(int i, int j, int[] ans, int[][] grid) {
        if (i < 0 || j < 0 || i >= grid.length || j >= grid[0].length || grid[i][j] == 0) {
            return;
        }

        grid[i][j] = 0;
        ans[0]++;

        dfs(i + 1, j, ans, grid);
        dfs(i - 1, j, ans, grid);
        dfs(i, j + 1, ans, grid);
        dfs(i, j - 1, ans, grid);
    }

    public int maxAreaOfIsland(int[][] grid) {
        int[] ans = new int[1];
        int result = 0;

        for (int i = 0; i < grid.length; i++) {
            for (int j = 0; j < grid[0].length; j++) {
                if (grid[i][j] == 1) {
                    ans[0] = 0;     
                    dfs(i, j, ans, grid);
                    result = Math.max(result, ans[0]);
                }
            }
        }

        return result;
    }
}