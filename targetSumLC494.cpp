//same as: count subsets with sum K
int findTargetSumWays(vector<int>& nums, int target) {
        int sum = 0, n = nums.size();
        for(int i = 0; i < n; i++){
            sum += nums[i];
        }
        int k = (sum-target)/2;
        if (sum-target < 0 || (sum-target)%2!=0){
            return 0;
        }
        vector<int> prev(k+1, 0);
        if (nums[0] == 0)
            prev[0] = 2;
        else
            prev[0] = 1;
        if (nums[0] != 0 and nums[0] <= k)
            prev[nums[0]] = 1;
        for(int i = 1; i < n; i++){
            vector<int> curr(k+1, 0);
            for(int t = 0; t <= k; t++){
                int notPick = prev[t];
                int pick = 0;
                if (t - nums[i] >= 0)
                    pick = prev[t - nums[i]];
                curr[t] = pick + notPick;
            }
            prev = curr;
        }
        return prev[k];
    }
