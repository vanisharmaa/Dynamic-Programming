//SPACE OPTIMIZATION
#include <bits/stdc++.h> 
int mod = (int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    if ((sum - d)%2 or sum < d)
        return 0;
    int k = (sum-d)/2;
    vector<int> prev(k+1, 0);
    if (arr[0] == 0)
        prev[0] = 2;
    else
        prev[0] = 1;
    if (arr[0] != 0 and arr[0] <= k)
        prev[arr[0]] = 1;
    for(int i = 1; i < n; i++){
        vector<int> curr(k+1, 0);
//         curr[0] = 1;
        for(int j = 0; j <= k; j++){
            int notPick = prev[j];
            int pick = 0;
            if (arr[i] <= j)
                pick = prev[j-arr[i]];
            curr[j] = (pick + notPick)%mod;
        }
        prev = curr;
    }
    return prev[k];
}

//TABULATION

#include <bits/stdc++.h> 
int mod = (int)(1e9+7);
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int sum = 0;
    for(int i = 0; i < n; i++)
        sum += arr[i];
    if ((sum - d)%2 or sum < d)
        return 0;
    int k = (sum-d)/2;
    vector<vector<int>> dp(n, vector<int>(k+1, 0));
    if(arr[0] == 0)
        dp[0][0] = 2;
    else 
        dp[0][0] = 1;
    if (arr[0] <= k and arr[0] != 0)
        dp[0][arr[0]] = 1;
    for(int i = 1; i < n; i++){
        for(int j = 0; j <= k; j++){
            int notPick = dp[i-1][j];
            int pick = 0;
            if (arr[i] <= j)
                pick = dp[i-1][j-arr[i]];
            dp[i][j] = (pick + notPick)%mod;
        }
    }
    return dp[n-1][k];
}

//MEMOIZATION

#include <bits/stdc++.h> 
int mod = (int)(1e9+7); 
int f(vector<int>& nums, int i, int tar, vector<vector<int>>& dp){
    if (tar < 0)
        return 0;
    if (i == 0){
        if (tar == 0 and nums[0] == 0)
            return 2;
        else if(tar == 0 || tar == nums[0])
            return 1;
        return 0;
    }
    if (dp[i][tar] != -1)
        return dp[i][tar];
    int notPick = f(nums, i-1, tar, dp);
    int pick = 0;
    if (tar - nums[i] >= 0)
        pick = f(nums, i-1, tar-nums[i], dp);
    return dp[i][tar] = (pick + notPick)%mod;
}
int findWays(vector<int> &num, int tar)
{
    vector<vector<int>> dp(num.size(), vector<int>(tar+1, -1));
    return f(num, num.size()-1, tar, dp);
}
int countPartitions(int n, int d, vector<int> &arr) {
    // Write your code here.
    int totSum = 0;
    for(int i = 0; i < n; i++)
        totSum += arr[i];
    int tar = (totSum - d)/2;
    if ((totSum - d) % 2 == 1 || totSum < d)
        return 0;
    return findWays(arr, tar);
}


