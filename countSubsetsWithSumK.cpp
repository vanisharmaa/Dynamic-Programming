//MEMOIZATION

#include <bits/stdc++.h> 
int f(vector<int> &num, int tar, int i, vector<vector<int>>& dp){
    if (tar < 0)
        return 0;
    if(i < 0){
        if (tar == 0){
            return 1;
        }
        else
            return 0;
    }
    if (dp[i][tar] != -1)
        return dp[i][tar];
    int pick = f(num, tar-num[i], i-1, dp);
    int notPick = f(num, tar, i-1, dp);
    return dp[i][tar] = pick+notPick;
}
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    return f(num, tar, num.size()-1, dp);
}
