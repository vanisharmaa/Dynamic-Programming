//SPACE OPTIMISATION
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    int prev2 = 0, prev = 0;
    for(int i = 1; i < n; i++){
        int x = abs(heights[i] - heights[i-1]) + prev;
        int y = INT_MAX;
        if (i > 1)
            y = abs(heights[i] - heights[i-2]) + prev2;
        int curr = min(x, y);
        prev2 = prev;
        prev = curr;
    }
    return prev;
}

//TABULATION
#include <bits/stdc++.h> 
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n, 0);
    dp[0] = 0;
    for(int i = 1; i < n; i++){
        int x = abs(heights[i] - heights[i-1]) + dp[i-1];
        int y = INT_MAX;
        if (i > 1)
            y = abs(heights[i] - heights[i-2]) + dp[i-2];
        dp[i] = min(x, y);
    }
    return dp[n-1];
}

//MEMOIZATION

#include <bits/stdc++.h> 
int f(int i, vector<int>& nums, vector<int>& dp){
    if (i == 0)
        return dp[0] = 0;
    int x = INT_MAX, y = INT_MAX;
    if (dp[i] != -1)
        return dp[i];
    if (i > 0)
        x = abs(nums[i] - nums[i-1]) + f(i-1, nums, dp);
    if (i > 1)
        y = abs(nums[i] - nums[i-2]) + f(i-2, nums, dp);
    return dp[i] = min(x, y);
}
int frogJump(int n, vector<int> &heights)
{
    // Write your code here.
    vector<int> dp(n+1, -1);
    return f(n-1, heights, dp);
}
