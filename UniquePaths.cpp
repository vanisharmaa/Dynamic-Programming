#include <bits/stdc++.h>
//SPACE OPTIMISED SOLUTION
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<int> dp(n, -1);
    dp[0] = 1;
    for(int j = 1; j < n; j++){
        dp[j] = dp[j-1];
    }
    for(int i = 1; i < m; i++){
        vector<int> temp(n, -1);
        for(int j = 0; j < n; j++){
            int up = 0, left = 0;
            up = dp[j];
            if(j > 0)
                left = temp[j-1];
            temp[j] = up + left;
        }
        dp = temp;
    }
    return dp[n-1];
}



//TABULATION SOLUTION
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    dp[0][0] = 1;
    for(int i = 0; i < m; i++){
        for (int j = 0; j < n; j++){
            if (i==0 && j == 0)
                continue;
            int up = 0, left = 0;
            if (i > 0)
                up = dp[i-1][j];
            if (j > 0)
                left = dp[i][j-1];
            dp[i][j] = up + left;
        }
    }
    return dp[m-1][n-1];
}



//MEMOIZATION SOLUTION
int helper(int m, int n, vector<vector<int>>& dp){
    if (m < 0 || n  < 0)
        return 0;
    if (m == 0 && n == 0){
        return dp[0][0] = 1;
    }
    if (dp[m][n] != -1)
        return dp[m][n];
    int up = helper(m-1, n, dp);
    int left = helper(m, n-1, dp);
    return dp[m][n] = up + left;
}
int uniquePaths(int m, int n) {
	// Write your code here.
    vector<vector<int>> dp(m, vector<int>(n, -1));
    return helper(m-1,n-1, dp);
}
