class Solution {
const int Mod = 1e9 + 7;
    
    // Memoization
    int solve(int i, int j, string& s, string& t, vector<vector<int>>& dp) {
        if(j >= t.length()) {
            return 1;
        }
        if(i >= s.length()) {
            return 0;
        }
        if(dp[i][j] != -1) {
            return dp[i][j];
        }
        
        int ans = 0;
        if(s[i] == t[j]) {
            ans = (ans % Mod + solve(i+1, j+1, s, t, dp) % Mod) % Mod;
        }
        ans = ans % Mod + solve(i+1, j, s, t, dp) % Mod;
        
        return dp[i][j] = ans % Mod;
    }
    
    // Tabulation
    int solveTab(string& s, string& t) {
        int n = s.length(), m = t.length();
        vector<vector<int>> dp(n+1, vector<int> (m+1, 0));
        
        for(int i=0; i<=n; i++) {
            dp[i][m] = 1;
            // dp[i][m-1] = 1;
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(s[i] == t[j]) {
                    ans = (ans % Mod + dp[i+1][j+1] % Mod) % Mod;
                }
                ans = ans % Mod + dp[i+1][j] % Mod;
                dp[i][j] = ans % Mod;
            }
        }
        
        return dp[0][0];
    }
    
    // Space Optimisation
    int spaceOptimised(string& s, string& t) {
        int n = s.length(), m = t.length();
        vector<int> curr(m+1, 0), next(m+1, 0);
        
        for(int i=0; i<=n; i++) {
            curr[m] = 1;
            next[m] = 1;
        }
        
        for(int i=n-1; i>=0; i--) {
            for(int j=m-1; j>=0; j--) {
                int ans = 0;
                if(s[i] == t[j]) {
                    ans = (ans % Mod + next[j+1] % Mod) % Mod;
                }
                ans = ans % Mod + next[j] % Mod;
                curr[j] = ans % Mod;
            }
            next = curr;
        }
        
        return curr[0];
    }
    public:
    int subsequenceCount(string s, string t)
    {
        vector<vector<int>> dp(s.length(), vector<int> (t.length(), -1));
        return solve(0, 0, s, t, dp);
        
        // return solveTab(s, t);
        
        // return spaceOptimised(s, t);
    }
};
 
