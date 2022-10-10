//SPACE OPTIMIZATION
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x){
    int n = num.size();
//     vector<vector<int>> dp(n, vector<int>(x+1, 0));
    vector<int> prev(x+1, 0);
    for(int i = 0; i <= x; i++){
        if (i%num[0] == 0)
            prev[i] = i/num[0];
        else
            prev[i] = 1e9;
    }
    for(int i = 1; i < n; i++){
        vector<int> curr(x+1, 0);
        for(int j = 0; j <= x; j++){
            int notTake = prev[j];
            int take = 1e9;
            if (j - num[i] >= 0)
                take = 1 + curr[j-num[i]];
            curr[j] = min(take, notTake);
        }
        prev = curr;
    }
    if (prev[x] >= 1e9)
        return -1;
    return prev[x];
}

//TABULATION
#include <bits/stdc++.h> 
int minimumElements(vector<int> &num, int x){
    int n = num.size();
    vector<vector<int>> dp(n, vector<int>(x+1, 0));
    for(int i = 0; i <= x; i++){
        if (i%num[0] == 0)
            dp[0][i] = i/num[0];
        else
            dp[0][i] = 1e9;
    }
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= x; j++){
            int notTake = dp[i-1][j];
            int take = 1e9;
            if (j - num[i] >= 0)
                take = 1 + dp[i][j-num[i]];
            dp[i][j] = min(take, notTake);
        }
    }
    if (dp[n-1][x] >= 1e9)
        return -1;
    return dp[n-1][x];
}


//MEMOIZATION

#include <bits/stdc++.h> 
int f(vector<int>& nums, int i, int target, vector<vector<int>>& dp){
    if (i == 0){
        if (target % nums[0] == 0)
            return target/nums[0];
        return 1e9;
    }
    if (dp[i][target] != -1)
        return dp[i][target];
    int notTake = f(nums, i-1, target, dp);
    int take = 1e9;
    if (target >= nums[i])
        take = 1 + f(nums, i, target - nums[i], dp);
    return dp[i][target] = min(take, notTake);
}
int minimumElements(vector<int> &num, int x)
{
    // Write your code here.
    vector<vector<int>> dp(num.size(), vector<int>(x+1, -1));
    int ans = f(num, num.size()-1, x, dp);
    if (ans > 1e8)
        return -1;
    return ans;
}
