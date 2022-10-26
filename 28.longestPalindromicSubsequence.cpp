//SPACE OPTIMIZATION
int longestPalindromeSubseq(string s) {
    string text1 = s;
    reverse(s.begin(), s.end());
    string text2 = s;
    //Q.26 code
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
