/*
You're given a triangular array/list 'TRIANGLE'. Your task is to return the minimun path sum to reach from the top to the bottom row.
The triangle array will have N rows and the i-th row, where 0<=i<N will have i+1 elements.
You can move only to the adjacent number of row below each step.
For example, if you are at index j in row, then you can move to i or i+1 index in row j+1 in each step.
*/

//TABULATION
int minimumPathSum(vector<vector<int>>& triangle, int n){
    vector<vector<int>> dp(n, vector<int>(n, 0));
    for(int i = 0; i < n; i++){
        dp[n-1][i] = triangle[n-1][i];
    }
    for(int i = n-2; i >= 0; i--){
        for(int j = i; j>= 0; j--){
            int down = triangle[i][j] + dp[i+1][j];
            int right = triangle[i][j] + dp[i+1][j+1];
            dp[i][j] = min(down, right);
        }
    }
    return dp[0][0];
}


//MEMOIZATION

int helper(vector<vector<int>>& triangle, int i, int j, int n, vector<vector<int>>& dp){
    if (i >= n || j > i)
        return 1e9;
    if(i == n-1)
        return dp[i][j] = triangle[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = triangle[i][j] + helper(triangle, i+1, j, n, dp);
    int right = triangle[i][j] + helper(triangle, i+1, j+1, n, dp);
    return dp[i][j] = min(down, right);
}
int minimumPathSum(vector<vector<int>>& triangle, int n){
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n, -1));
    return helper(triangle, 0, 0, n, dp);
}
