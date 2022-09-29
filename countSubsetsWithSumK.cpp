//SPACE OPTIMISATION
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<int> prev(tar+1, 0);
    prev[0] = 1;
    if (num[0] <= tar)
        prev[num[0]] = 1;
    for(int i = 1; i < n; i++){
        vector<int> curr(tar+1, 0);
        curr[0] = 1;
        for(int j = 0; j <= tar; j++){
            int notTake, take = 0;
            notTake = prev[j];
            if (num[i] <= j)
                take = prev[j-num[i]];
            curr[j] = notTake + take;
        }
        prev = curr;
    }
    return prev[tar];
}

//TABULATION
int findWays(vector<int> &num, int tar)
{
    // Write your code here.
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(tar+1, 0));
    for(int i = 0; i < n; i++){
        dp[i][0] = 1;
    }
    if (num[0] <= tar)
        dp[0][num[0]] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= tar; j++){
            int notTake, take = 0;
            notTake = dp[i-1][j];
            if (num[i] <= j)
                take = dp[i-1][j-num[i]];
            dp[i][j] = notTake + take;
        }
    }
    return dp[n-1][tar];
}

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
