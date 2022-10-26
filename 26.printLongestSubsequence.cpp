void longestCommonSubsequence(string text1, string text2) {
  //Tabuulation Code for longest common subsequence
    vector<vector<int>> dp(text1.size()+1, vector<int>(text2.size()+1, -1));
    for(int i = 0; i <= text1.size(); i++)
        dp[i][0] = 0;
    for(int i = 0; i <= text2.size(); i++)
        dp[0][i] = 0;
    for(int i = 1; i <= text1.size(); i++){
        for(int j = 1; j <= text2.size(); j++){
            if (text1[i-1] == text2[j-1]){
                dp[i][j] = 1 + dp[i-1][j-1];
            }
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }
    // cout << "xxxxxxxxxxxxxxx" << endl;
    // for(int i = 0; i <= text1.size(); i++){
    //     for(int j = 0; j<=text2.size(); j++){
    //         cout << dp[i][j] << " ";
    //     }
    //     cout << endl;
    // }
    // cout << "xxxxxxxxxxxxxxx" << endl;
    string ans = "";
    for(int x = 0; x < dp[text1.size()][text2.size()]; x++)
        ans += '$';
    int ind = dp[text1.size()][text2.size()]-1;
    int i = text1.size(), j = text2.size();
    while(i > 0 and j > 0){
        if (text1[i-1] == text2[j-1]){
            ans[ind--] = text1[i-1];
            i--, j--;
        }
        else if(dp[i-1][j] > dp[i][j-1]){
            i--;
        }
        else{
            j--;
        }
    }
    cout << ans << endl;
}
