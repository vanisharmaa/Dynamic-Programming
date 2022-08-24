//TABULATION SOLUTION

#include<bits/stdc++.h>
using namespace std;

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));
    for(int i = 0; i < 3; i++){
        dp[0][0] = max(points[0][1], points[0][2]);
        dp[0][1] = max(points[0][0], points[0][2]);
        dp[0][2] = max(points[0][1], points[0][0]);
        dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    }
    for(int day = 1; day < n; day++){
        for (int last = 0; last < 4; last++){
            for(int task = 0; task < 3; task++){
                if (task != last){
                    int activity = points[day][task] + dp[day-1][task];
                    if (activity > dp[day][last])
                        dp[day][last] = x;
                }
            }
        }       
    }
    return dp[n-1][3];
}


//MEMOIZATION SOLUTION

#include<bits/stdc++.h>
using namespace std;

int helper(int n, vector<vector<int>> &points, int lastDay, vector<vector<int>>& dp){
    if (n == 0){
        int maxi = -10e8;
        for (int i = 0; i < 3; i++){
            if (i != lastDay){
                if (maxi < points[n][i])
                    maxi = points[0][i];
            }
        }
        return maxi;
    }
    if (dp[n][lastDay] != -1)
        return dp[n][lastDay];
    int ans = -10e8;
    for(int i = 0; i < 3; i++){
        if (i != lastDay){
            int x = points[n][i] + helper(n-1, points, i, dp);
            if (x > ans)
                ans = x;
        }
    }
    return dp[n][lastDay] = ans;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    return helper(n-1, points, 3, dp);
}
