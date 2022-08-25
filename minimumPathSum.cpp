/*
Ninjaland is a country in the shape of a 2-D grid 'GRID', with 'N' rows and 'M' coulmns.
Each point in the grid has some cost associated with it.
Find a path from top left i.e (0,0) to the bottom right i.e ('N'-1, 'M'-1) which minimizes the sum of the ocst of all the numbers along the path.
You need to tell the minimum sum of the path.
*/

int helper(int i, int j, vector<vector<int>>& grid, vector<vector<int>>& dp){
    if (i == 0 && j == 0){
        return dp[0][0] = grid[i][j];
    }
    if (i < 0 || j < 0)
        return 1e9;
    if (dp[i][j] != -1)
        return dp[i][j];
    int up = grid[i][j] + helper(i-1, j, grid, dp);
    int left = grid[i][j] + helper(i, j-1, grid, dp);
    return dp[i][j] = min(up, left);
}
int minSumPath(vector<vector<int>> &grid) {
    // Write your code here
    int n = grid.size();
    int m = grid[0].size();
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n-1, m-1, grid, dp);
}
