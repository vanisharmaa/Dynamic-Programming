//SPACE OPTIMISATION    
#include <bits/stdc++.h> 
bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<bool> next(k+1, false);
    next[0] = true;
    if (arr[0] <= k)
        next[arr[0]] = true;
    for(int i = 1; i < n; i++){
        vector<bool> curr(k+1, false);
        curr[0] = true;
        for(int j = 1; j <= k; j++){
            bool notTake = next[j];
            bool take = false;
            if (arr[i] <= j){
                take = next[j-arr[i]];
            }
            curr[j] = take || notTake;
        }
        next = curr;
    }
    return next[k];
}

//TABULATION SOLUTION
#include <bits/stdc++.h> 

bool subsetSumToK(int n, int k, vector<int> &arr) {
    // Write your code here.
    vector<vector<bool>> dp(n, vector<bool>(k+1, false));
    for(int i = 0; i < n; i++){
        dp[i][0] = true;
    }
    if (arr[0] <= k)
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
