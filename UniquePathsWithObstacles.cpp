int mod = int(1e9 + 7);
//TABULATION
int mazeObstacles(int n, int m, vector< vector< int> > &mat) {
    // Write your code here
    vector<vector<int>> dp(n, vector<int>(m, 0));
    dp[0][0] = 1;
    for(int i = 0; i < n; i++){
        for (int j = 0; j < m; j++){
            if (i == 0 && j == 0)
                continue;
            int up = 0, left = 0;
            if (i > 0 && mat[i-1][j] != -1)
                up = dp[i-1][j];
            if (j > 0 && mat[i][j-1] != -1)
                left = dp[i][j-1];
            dp[i][j] = (up + left)%mod;
        }    
    }
    return dp[n-1][m-1];
}



//MEMOIZATION
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
