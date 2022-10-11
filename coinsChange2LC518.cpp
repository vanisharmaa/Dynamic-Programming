//TABULATION
int change(int amount, vector<int>& coins) {
  int n = coins.size();
  vector<vector<int>> dp(n, vector<int>(amount+1, 0));
  for(int tar = 0; tar <= amount; tar++){
      if(tar % coins[0] == 0)
          dp[0][tar] = 1;
      else
          dp[0][tar] = 0;
  }
  for(int i = 1; i < n; i++){
      for(int tar = 0; tar <= amount; tar++){
          int notPick = dp[i-1][tar], pick = 0;
          if (tar - coins[i] >= 0)  
              pick = dp[i][tar-coins[i]];
          dp[i][tar] = pick + notPick;
      }
  }
  return dp[n-1][amount];
}

//MEMOIZATION
int f(int tar, vector<int>& arr, int i, vector<vector<int>>& dp){
      if (i == 0){
          if(tar % arr[0] == 0)
              return 1;
          return 0;
      }
      if (dp[i][tar] != -1)
          return dp[i][tar];
      int notPick = f(tar, arr, i-1, dp), pick = 0;
      if (tar - arr[i] >= 0)  
          pick = f(tar-arr[i], arr, i, dp);
      return dp[i][tar] = pick + notPick;
  }
  int change(int amount, vector<int>& coins) {
      vector<vector<int>> dp(coins.size(), vector<int>(amount+1, -1));
      return f(amount, coins, coins.size()-1, dp);
  }
