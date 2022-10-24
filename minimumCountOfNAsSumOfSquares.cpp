//TABULATION
int minCount(int n)
{
	//Write your code here
    vector<int> dp(n+1, -1);
    dp[0] = 0;
    for(int j = 1; j<= n; j++){
        int mini = 1e8;
        for(int i = 1; i*i <= j; i++){
            int ans = 1e8;
            if (n - i*i >= 0)
                ans = 1 + f(j-i*i, dp);
            mini = min(mini, ans);
        }
        dp[j] = mini;
    }
    return dp[n];
    
}

//MEMOIZATION
int f(int n, vector<int>& dp){
    if (n == 0)
        return 0;
    if (dp[n] != -1)
        return dp[n];
    int mini = 1e8;
    for(int i = 1; i*i <= n; i++){
        int ans = 1e8;
        if (n - i*i >= 0)
            ans = 1 + f(n-i*i, dp);
        mini = min(mini, ans);
    }
    return dp[n] = mini;
}
int minCount(int n)
{
	//Write your code here
    vector<int> dp(n+1, -1);
    return f(n, dp);
}
