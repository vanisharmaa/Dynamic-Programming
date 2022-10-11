//MEMOIZATION
#include <bits/stdc++.h> 
int f(int i, int W, vector<int>& profit, vector<int>& weight, vector<vector<int>>& dp){
    if (i == 0){
        if (W == 0){
            return 0;
        }
        return profit[0]*(W/weight[0]);
    }
    if (dp[i][W] != -1)
        return dp[i][W];
    int notPick = f(i-1, W, profit, weight, dp);
    int pick = 0;
    if (W - weight[i] >= 0)
        pick = profit[i] + f(i, W - weight[i], profit, weight, dp);
    return dp[i][W] = max(pick, notPick);    
}
int unboundedKnapsack(int n, int w, vector<int> &profit, vector<int> &weight)
{
    // Write Your Code Here.
    vector<vector<int>> dp(n, vector<int>(w+1, -1));
    return f(n-1, w, profit, weight, dp);
}
