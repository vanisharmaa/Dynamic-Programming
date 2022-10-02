//SPACE OPTIMISATION
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<int> prev(4, 0);
    prev[0] = max(points[0][1], points[0][2]);
    prev[1] = max(points[0][0], points[0][2]);
    prev[2] = max(points[0][0], points[0][1]);
    prev[3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++){
        vector<int> curr(4, 0);
        for(int lastTask = 0; lastTask < 4; lastTask++){
            int maxi = -1e8;
            for(int i = 0; i < 3; i++){
                int ans = -1e8;
                if (i != lastTask){
                    ans = points[day][i] + prev[i];
                }
                maxi = max(maxi, ans);
            }
            curr[lastTask] = maxi;
        }
        prev = curr;
    }
    int ans = -1e8;
    for(int i = 0; i < 4; i++){
        ans = max(prev[i], ans);
    }
    return ans;
}

//TABULATION
int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, 0));
    dp[0][0] = max(points[0][1], points[0][2]);
    dp[0][1] = max(points[0][0], points[0][2]);
    dp[0][2] = max(points[0][0], points[0][1]);
    dp[0][3] = max(points[0][0], max(points[0][1], points[0][2]));
    
    for(int day = 1; day < n; day++){
        for(int lastTask = 0; lastTask < 4; lastTask++){
            int maxi = -1e8;
            for(int i = 0; i < 3; i++){
                int ans = -1e8;
                if (i != lastTask){
                    ans = points[day][i] + dp[day-1][i];
                }
                maxi = max(maxi, ans);
            }
            dp[day][lastTask] = maxi;
        }
    }
    int ans = -1e8;
    for(int i = 0; i < 4; i++){
        ans = max(dp[n-1][i], ans);
    }
    return ans;
}

//MEMOIZATION

int f(int day, vector<vector<int>>& points, int lastTask, vector<vector<int>>& dp){
    if (day == 0){
        int ans = -1e8;
        for(int i = 0; i < 3; i++){
            if (i != lastTask){
                ans = max(ans, points[0][i]);
            }
        }
        return ans;
    }
    if (dp[day][lastTask] != -1)
        return dp[day][lastTask];
    int maxi = -1e8;
    for(int i = 0; i < 3; i++){
        int ans = -1e8;
        if (i != lastTask){
            ans = points[day][i] + f(day-1, points, i, dp);
        }
        maxi = max(maxi, ans);
    }
    return dp[day][lastTask] = maxi;
}

int ninjaTraining(int n, vector<vector<int>> &points)
{
    // Write your code here.
    vector<vector<int>> dp(n, vector<int>(4, -1));
    int lastTask = 3;
    return f(n-1, points, lastTask, dp);
}
