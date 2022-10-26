//Space Optimization 
int longestCommonSubsequence(string text1, string text2) {
    vector<int> prev(text2.size()+1, 0);
    for(int i2 = 0; i2 <= text2.size(); i2++){
        prev[i2] = 0;
    }
    for(int i1 = 1; i1 <= text1.size(); i1++){
        vector<int> curr(text2.size()+1, 0);
        curr[0] = 0;
        for(int i2 = 1; i2 <= text2.size(); i2++){
            if (text1[i1-1] == text2[i2-1])
                curr[i2] = 1 + prev[i2-1];
            else
                curr[i2] = max(prev[i2], curr[i2-1]);
        }
        prev = curr;
    }
    return prev[text2.size()];
}

//Tabulation
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
    for(int i1 = 0; i1 <= text1.size(); i1++){
        dp[i1][0] = 0;
    }
    for(int i2 = 0; i2 <= text2.size(); i2++){
        dp[0][i2] = 0;
    }
    for(int i1 = 1; i1 <= text1.size(); i1++){
        for(int i2 = 1; i2 <= text2.size(); i2++){
            if (text1[i1-1] == text2[i2-1])
                dp[i1][i2] = 1 + dp[i1-1][i2-1];
            else
                dp[i1][i2] = max(dp[i1-1][i2], dp[i1][i2-1]);
        }
    }
    return dp[text1.size()][text2.size()];
}

//Memoization
int f(string text1, int i1, string text2, int i2, vector<vector<int>>& dp){
    if (i1 < 0 || i2 < 0){
        return 0;
    }
    if (dp[i1][i2] != -1)
        return dp[i1][i2];
    if (text1[i1] == text2[i2])
        return dp[i1][i2] = 1 + f(text1, i1-1, text2, i2-1, dp);
    return dp[i1][i2] = max(f(text1, i1-1, text2, i2, dp), f(text1, i1, text2, i2-1, dp));
}
int longestCommonSubsequence(string text1, string text2) {
    vector<vector<int>> dp(text1.size(), vector<int>(text2.size(), -1));
    return f(text1, text1.size()-1, text2, text2.size()-1, dp);
}
