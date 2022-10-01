//SPACE OPTIMISATION

int main(){
  int n;
  cin >> n;
  int prev2 = 0, prev = 1;
  for(int i = 2; i <= n; i++){
    int curr = prev2 + prev;
    prev2 = prev;
    prev = curr;
  }
  return prev;
}

//TABULATION

int main(){
  int n;
  cin >> n;
  vector<int> dp(n+1, 0);
  dp[0] = 0;
  dp[1] = 1;
  for(int i = 2; i <= n; i++){
    dp[i] = dp[i-1] + dp[i-2];
  }
  return dp[n];
}

//MEMOIZATION

int fib(int n, vector<int>& dp){
  if (n == 0 || n == 1)
    return dp[n] = n;
  if (dp[n] != -1)
    return dp[n];
  return dp[n] = fib(n-1, dp) + fib(n-2, dp);
}
int main(){
  int n;
  cin >> n;
  vector<int> dp(n+1, -1);
  return fib(n, dp);
}

