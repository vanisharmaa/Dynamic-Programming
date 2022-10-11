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
