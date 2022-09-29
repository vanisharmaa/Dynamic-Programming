//Space Optimised

#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int totalSum = 0;
    for(int i = 0; i < n; i++){
        totalSum += arr[i];
    }
    int target = totalSum;
    vector<bool> prev(target+1, false);
    prev[0] = true;
    if (arr[0] <= target)
        prev[arr[0]] = true;
    for(int i = 1; i < n; i++){
        vector<bool> curr(target+1, false);
        curr[0] = true;
        for(int k = 1; k <= target; k++){
            bool notTaken = prev[k];
            bool taken = false;
            if (arr[i] <= k)
                taken = prev[k-arr[i]];
            curr[k] = taken || notTaken;
        }
        prev = curr;
    }
    int mini = totalSum;
    for(int i = 0; i <= target; i++){
        int sum1 = 0, sum2 = totalSum;
        if (prev[i]){
            sum1 += i;
            sum2 -= i;
            mini = min(mini, abs(sum1-sum2));
        }
    }
    return mini;
}
