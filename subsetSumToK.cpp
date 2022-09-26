#include <bits/stdc++.h>

//Memoization Solution
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
