#include<bits/stdc++.h>
using namespace std;

int helper(int n, vector<vector<int>> &points, int lastDay, vector<vector<int>>& dp){
    if (n == 0){
        int maxi = -10e8;
        for (int i = 0; i < 3; i++){
            if (i != lastDay){
                if (maxi < points[n][i])
                    maxi = points[0][i];
            }
        }
        return maxi;
    }
    if (dp[n][lastDay] != -1)
        return dp[n][lastDay];
    int ans = -10e8;
    for(int i = 0; i < 3; i++){
        if (i != lastDay){
            int x = points[n][i] + helper(n-1, points, i, dp);
            if (x > ans)
                ans = x;
        }
    }
    return dp[n][lastDay] = ans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(n-1, points, 3, dp);
}
