//SPACE OPTIMISATION

//TABULATION
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    if (obstacleGrid[0][0] == 1 || obstacleGrid[m-1][n-1] == 1)
        return 0;
    vector<vector<int>> dp(m, vector<int>(n, 0));
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for(int j = 0; j < n; j++){
            if (i==0 && j == 0)
                continue;
            if (obstacleGrid[i][j] == 1)
                continue;
            int down = 0, right = 0;
            if (i > 0)
                down = dp[i-1][j];
            if (j > 0)
                right = dp[i][j-1];
            dp[i][j] = down + right;
        }
    }
    return dp[m-1][n-1];
}

//MEMOIZATION

int f(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if (i < 0 || j < 0 || grid[i][j] == 1)
        return 0;
    if (i == 0 && j == 0)
        return dp[0][0] = 1;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = f(i-1, j, grid, dp);
    int left = f(i, j-1, grid, dp);
    return dp[i][j] = up + left;
}
int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
    int m = obstacleGrid.size();
    int n = obstacleGrid[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return f(m-1, n-1, obstacleGrid, dp);
}
