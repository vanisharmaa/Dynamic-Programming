//TABULATION
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n+1, 0));
    for(int N = 1; N <= n; N++){
        if (n == 0)
            dp[0][N] = 0;
        else
            dp[0][N] = price[0]*N;
    }
    for(int i = 1; i < n; i++){
        for(int N = 1; N <= n; N++){
            int notPick = dp[i-1][N];
            int pick = -1e9;
            int rodLen = i+1;
            if (rodLen <= N)
                pick = price[i] + dp[i][N-rodLen];
            dp[i][N] = max(pick, notPick);
        }
    }
    return dp[n-1][n];
}


//MEMOIZATION
int f(vector<int>& price, int i, int N, vector<vector<int>>& dp){
    if (i == 0){
        if (N == 0)
            return 0;
        return price[0]*(N);
    }
    if (dp[i][N] != -1)
        return dp[i][N];
    int notPick = f(price, i-1, N, dp);
    int pick = -1e9;
    int rodLen = i+1;
    if (rodLen <= N)
        pick = price[i] + f(price, i, N-rodLen, dp);
    return dp[i][N] = max(pick, notPick);
    
}
int cutRod(vector<int> &price, int n)
{
	// Write your code here.
    vector<vector<int>> dp(n, vector<int>(n+1, -1));
    return f(price, n-1, n, dp);
}
