//SPACE OPTIMIZATION
#include <bits/stdc++.h>
int mod = 1e9+7;
int countDistinctWays(int n) {
    //  Write your code here.
    int prev2 = 1, prev = 1;
    for(int i = 2; i <= n; i++){
        int curr = (prev2 + prev)%mod;
        prev2 = prev;
        prev = curr;
    }
    return prev;
}


//TABULATION
#include <bits/stdc++.h>
int mod = 1e9+7;
int countDistinctWays(int n) {
    //  Write your code here.
    vector<int> dp(n+1, 0);
    dp[0] = dp[1] = 1;
    for(int i = 2; i <= n; i++)
        dp[i] = (dp[i-1] + dp[i-2])%mod;
    return dp[n];
}

//MEMOIZATION

#include <bits/stdc++.h>
int mod = 1e9+7;
int f(int n, vector<int>& dp){
    if (n == 0 or n == 1)
        return dp[n] = 1;
    if (dp[n] != -1)
        return dp[n];
    return dp[n] = (f(n-1, dp) + f(n-2, dp))%mod;
}
int countDistinctWays(int n) {
    //  Write your code here.
    vector<int> dp(n+1, -1);
    return f(n, dp);
}
