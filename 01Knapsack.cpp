//MORE SPACE OPTIMIZATION
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<int> prev(maxWeight+1, 0);
    for(int j = 0; j <= maxWeight; j++){
        if(weight[0] <= j)
            prev[j] = value[0];
    }
    for(int i = 1; i < n; i++){
        for(int j = maxWeight; j >= 0; j--){
            int notPick = prev[j];
            int pick = INT_MIN;
            if (weight[i] <= j)
                pick = value[i] + prev[j-weight[i]];
            prev[j] = max(pick, notPick);
        }
    }
    return prev[maxWeight];
}

//SPACE OPTIMIZATION
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<int> prev(maxWeight+1, 0);
    for(int j = 0; j <= maxWeight; j++){
        if(weight[0] <= j)
            prev[j] = value[0];
    }
    for(int i = 1; i < n; i++){
        vector<int> curr(maxWeight+1, 0);
        for(int j = 0; j <= maxWeight; j++){
            int notPick = prev[j];
            int pick = INT_MIN;
            if (weight[i] <= j)
                pick = value[i] + prev[j-weight[i]];
            curr[j] = max(pick, notPick);
        }
        prev = curr;
    }
    return prev[maxWeight];
}

//TABULATION

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, 0));
    for(int j = 0; j <= maxWeight; j++){
        if(weight[0] <= j)
            dp[0][j] = value[0];
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= maxWeight; j++){
            int notPick = dp[i-1][j];
            int pick = INT_MIN;
            if (weight[i] <= j)
                pick = value[i] + dp[i-1][j-weight[i]];
            dp[i][j] = max(pick, notPick);
        }
    }
    return dp[n-1][maxWeight];
}

//MEMOIZATION

#include <bits/stdc++.h> 

int f(vector<int>& weight, vector<int>& value, int i, int w, vector<vector<int>>& dp){
    if (w < 0)
        return 0;
    if (i == 0){
        if (weight[0] <= w)
            return value[0];
        return 0;
    }
    if (dp[i][w] != -1)
        return dp[i][w];
    int notPick = f(weight, value, i-1, w, dp);
    int pick = 0;
    if (weight[i] <= w)
        pick = value[i] + f(weight, value, i-1, w-weight[i], dp);
    return dp[i][w] = max(pick, notPick);
}

int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
	// Write your code here
    vector<vector<int>> dp(n, vector<int>(maxWeight+1, -1));
    return f(weight, value, n-1, maxWeight, dp);
}
