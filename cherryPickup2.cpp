class Solution {
public:
    //TABULATION
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        for(int j1 = 0 ; j1 < cols; j1++){
            for(int j2 = 0; j2 < cols; j2++){
                if (j1 == j2)
                    dp[rows-1][j1][j2] = grid[rows-1][j1];
                else
                    dp[rows-1][j1][j2] = grid[rows-1][j1] + grid[rows-1][j2];
            }
        }
        for(int i = rows-2; i >= 0; i--){
            for(int j1 = 0; j1 < cols; j1++){
                for(int j2 = 0; j2 < cols; j2++){
                    int maxi = -1e8;
                    for(int dj1 = -1; dj1 <= 1; dj1++){
                        for(int dj2 = -1; dj2 <= 1; dj2++){
                            int ans = -1e8;
                            if(j1+dj1 < 0 || j1+dj1 >= cols ||j2+dj2 < 0 || j2+dj2 >= cols)
                                ;
                            else{
                            if (j1 == j2)
                                ans = grid[i][j1] + dp[i+1][j1 + dj1][j2 + dj2];
                            else
                                ans = grid[i][j1] + grid[i][j2] + dp[i+1][j1 + dj1][j2 + dj2];
                            maxi = max(maxi, ans);
                            }
                        }
                    }
                    dp[i][j1][j2] = maxi;
                }
            }
        }
        return dp[0][0][cols-1];
    }
};
    
    
    //MEMOIZATION
    int f(vector<vector<int>>& grid, int i, int j1, int j2, int n, int m, vector<vector<vector<int>>>& dp){
        if(j1 < 0 || j2 < 0 || j1 >= m || j2 >= m)
            return -1e8;
        if(i == n-1){
            if (j1 == j2)
                return dp[i][j1][j2] = grid[i][j1];
            else
                return dp[i][j1][j2] = grid[i][j1] + grid[i][j2];
        }

        if (dp[i][j1][j2] != -1)
            return dp[i][j1][j2];
        int maxi = -1e8;
        for(int dj1 = -1; dj1 <= 1; dj1++){
            for(int dj2 = -1; dj2 <= 1; dj2++){
                int ans = -1e8;
                if (j1 == j2)
                    ans = grid[i][j1] + f(grid, i+1, j1 + dj1, j2 + dj2, n, m, dp);
                else
                    ans = grid[i][j1] + grid[i][j2] + f(grid, i+1, j1 + dj1, j2 + dj2, n, m, dp);
                maxi = max(maxi, ans);
            }
        }
        return dp[i][j1][j2] = maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int rows = grid.size();
        int cols = grid[0].size();
        vector<vector<vector<int>>> dp(rows, vector<vector<int>>(cols, vector<int>(cols, -1)));
        int i = 0, j1 = 0, j2 = cols-1;
        return f(grid, i, j1, j2, rows, cols, dp);
    }
};
