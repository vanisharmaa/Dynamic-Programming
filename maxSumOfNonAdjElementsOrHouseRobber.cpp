//SPACE OPTIMISATION
int rob(vector<int>& nums) {
        int n = nums.size();
        int prev = nums[0];
        int prev2 = INT_MAX;
        for(int i = 1; i < n; i++){
            int notPick = prev;
            int pick = nums[i];
            if (i > 1)
                pick += prev2;
            int curr = max(pick, notPick);
            prev2 = prev;
            prev = curr;
        }
        return prev;
}

//TABULATION

int rob(vector<int>& nums) {
        int n = nums.size();
        vector<int> dp(n, 0);
        dp[0] = nums[0];
        for(int i = 1; i < n; i++){
            int notPick = dp[i-1];
            int pick = nums[i];
            if (i > 1)
                pick += dp[i-2];
            dp[i] = max(pick, notPick);
        }
        return dp[n-1];
}

//MEMOIZATION

int f(int ind, vector<int>& nums, vector<int>& dp){
        if (ind == 0)
            return nums[0];
        if (dp[ind] != -1)
           return dp[ind];
        int pick = nums[ind];
        if (ind > 1)
            pick += f(ind-2, nums, dp);
        int notPick = f(ind-1, nums, dp);
        return dp[ind] = max(pick, notPick);
        
}
int rob(vector<int>& nums) {
        vector<int> dp(nums.size(), -1);
        return f(nums.size()-1, nums, dp);
}
