/*

You have been given an N*M matrix filled with integer numbers. Find the maximum sum that can be obtained from a path starting from any cell in the first row to any cell in the last row.
From a cell in a row, you can move to another cell directly below that row, or diagonally below left or right.
So from a particular cell(row, col), we can move in three directions i.e
Down: (row+1, col)
Down left diagonal: (row+1, col-1)
Down right diagonal: (row+1, col+1)

*/

//SPACE OPTIMISATION

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    vector<int> prev(n, 0);
    vector<int> curr(n, 0);
    for(int i = 0; i < n; i++){
        prev[i] = matrix[0][i];
    }
    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
                int up = matrix[i][j] + prev[j];
                int left = -1e9;
                if (j > 0)
                    left = matrix[i][j] + prev[j-1];
                int right = -1e9;
                if (j < n-1)
                    right = matrix[i][j] + prev[j+1];
                curr[j] = max(up, max(left, right));
        }
        prev = curr;
    }
    int maxi = -1e9;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, prev[i]);
    }
    return maxi;
}



//TABULATION

int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    for(int i = 0; i < n; i++){
        dp[0][i] = matrix[0][i];
    }
    for(int i = 1; i < m; i++){
        for(int j = 0; j < n; j++){
                int up = matrix[i][j] + dp[i-1][j];
                int left = -1e9;
                if (j > 0)
                    left = matrix[i][j] + dp[i-1][j-1];
                int right = -1e9;
                if (j < n-1)
                    right = matrix[i][j] + dp[i-1][j+1];
                dp[i][j] = max(up, max(left, right));
        }
    }
    int maxi = -1e9;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, dp[m-1][i]);
    }
    return maxi;
}



//MEMOIZATION

int helper(vector<vector<int>> &matrix, int m, int n, int i, int j, vector<vector<int>> &dp){
    if (i >= m)
        return -1e9;
    if (j < 0 || j >= n)
        return -1e9;
    if(i == m-1)
        return dp[i][j] = matrix[i][j];
    if (dp[i][j] != -1)
        return dp[i][j];
    int down = matrix[i][j] + helper(matrix, m, n, i+1, j, dp);
    int left = matrix[i][j] + helper(matrix, m, n, i+1, j-1, dp);
    int right = matrix[i][j] + helper(matrix, m, n, i+1, j+1, dp);
    return dp[i][j] = max(down, max(left, right));
}
int getMaxPathSum(vector<vector<int>> &matrix)
{
    //  Write your code here.
    int m = matrix.size();
    int n = matrix[0].size();
    vector<vector<int>> dp(m, vector<int>(n, -1));
    vector<int> col(n, -1);
    for(int i = 0; i < n; i++){
        col[i] = helper(matrix, m, n, 0, i, dp);
    }
    int maxi = -1e9;
    for(int i = 0; i < n; i++){
        maxi = max(maxi, col[i]);
    }
    return maxi;
}
