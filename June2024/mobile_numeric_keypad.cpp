class Solution {
  public:
    long long getCount(int n) {
        vector<vector<int>> grid = {
            {1, 2, 3},
            {4, 5, 6},
            {7, 8, 9},
            {-1, 0, -1},
        };
        
        long long cnt = 0;
        vector<vector<vector<long long>>> dp(n + 1, vector<vector<long long>>(4, vector<long long>(3, -1)));
    
        for (int i = 0; i < 4; i++) {
            for (int j = 0; j < 3; j++) {
                if (grid[i][j] != -1) {
                    cnt += dfs(n, i, j, grid, dp);
                }
            }
        }
        return cnt;
    }
    
    long long dfs(int n, int i, int j, vector<vector<int>>& grid, vector<vector<vector<long long>>>& dp) {
        if (grid[i][j] == -1) {
            return 0;
        }
        if (n == 1) {
            return 1;
        }
        if (dp[n][i][j] != -1) {
            return dp[n][i][j];
        }
    
        int dx[] = {0, -1, 0, 1, 0};
        int dy[] = {0, 0, 1, 0, -1};
        long long cnt = 0;
    
        for (int k = 0; k < 5; k++) {
            int newx = i + dx[k];
            int newy = j + dy[k];
            if (newx >= 0 && newx < 4 && newy >= 0 && newy < 3 && grid[newx][newy] != -1) {
                cnt += dfs(n - 1, newx, newy, grid, dp);
            }
        }
    
        return dp[n][i][j] = cnt;
    }    
};
