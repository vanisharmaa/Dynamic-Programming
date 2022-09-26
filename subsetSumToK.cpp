//TABULATION SOLUTION
#include <bits/stdc++.h> 

bool f(int i, int k, vector<int>& arr, vector<vector<int>> &dp){
    if (k == 0)
        return true;
    if (i < 0)
        return false;
    if (dp[i][k] != -1)
        return dp[i][k];
    bool notTake = f(i-1, k, arr, dp);
    bool take = false;
    if (arr[i] <= k){
        take = f(i-1, k-arr[i], arr, dp);
    }
    return dp[i][k] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    dp[0][arr[0]] = true;
    for(int i = 1; i < n; i++){
        for(int j = 1; j <= k; j++){
            bool notTake = dp[i-1][j];
            bool take = false;
            if (arr[i] <= j){
                take = dp[i-1][j-arr[i]];
            }
            dp[i][j] = take || notTake;
        }
    }
    return dp[n-1][k];
}

//Memoization Solution

#include <bits/stdc++.h>
bool f(int i, int k, vector<int>& arr, vector<vector<int>> &dp){
    if (k == 0)
        return true;
    if (i < 0)
        return false;
    if (dp[i][k] != -1)
        return dp[i][k];
    bool notTake = f(i-1, k, arr, dp);
    bool take = false;
    if (arr[i] <= k){
        take = f(i-1, k-arr[i], arr, dp);
    }
    return dp[i][k] = take || notTake;
}
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(k+1, -1));
    return f(n-1, k, arr, dp);
}
