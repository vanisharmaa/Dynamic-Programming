#include <bits/stdc++.h> 
int minSubsetSumDifference(vector<int>& arr, int n)
{
	// Write your code here.
    int sum = 0;
    for(int i = 0; i < n; i++){
        sum += arr[i];
    }
  
    //DP14 Code
    vector<bool> prev(sum+1, false);
    prev[0] = true;
    if (arr[0] <= sum)
        prev[arr[0]] = true;
    for(int i = 1; i < n; i++){
        vector<bool> curr(sum+1, false);
        curr[0] = true;
        for(int j = 1; j <= sum; j++){
            bool pick = false;
            if (arr[i] <= j)
                pick = prev[j-arr[i]];
            bool notPick = prev[j];
            curr[j] = pick || notPick;
        }
        prev = curr;
    }
    //DP14 code ends
  
    int mini = 1e9;
    for(int i = 0; i <= sum; i++){
        int ans = 1e9;
        if (prev[i]){
            ans = i;
        }
        mini = min(mini, abs(ans - (sum - ans)));
    }
    return mini;
}
