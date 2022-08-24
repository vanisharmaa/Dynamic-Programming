int mod = int(1e9 + 7);
int helper(int n, int m, vector<vector<int>> &mat, vector<vector<int>> &dp){
    if(n==0 && m == 0)
        return dp[0][0] = 1;
    if (n < 0 || m < 0)
        return 0;
    if (dp[n][m] != -1)
        return dp[n][m];
    int up = 0, left = 0;
    if (n > 0 && mat[n-1][m] != -1)
        up = helper(n-1, m, mat, dp);
    if (m > 0 && mat[n][m-1] != -1)
        left = helper(n, m-1, mat, dp);
    return dp[n][m] = (up + left) % mod;
}

int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, -1));
    return helper(n-1, m-1, mat, dp);
}
