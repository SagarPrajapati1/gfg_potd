REC + Memo :
int solve(int i, int j, int a[], int b[], vector<vector<int>> &dp) 
    { 
        if(j<0){
            return 0;
        }
        
        if(i<0){
            return -1e9;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
      
        int notpick = 0 + solve(i-1, j, a, b, dp);
        int pick = a[i]*b[j] + solve(i-1, j-1, a, b, dp);
        
        return dp[i][j] = max(notpick, pick);
    }
    
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(n, vector<int>(m, -1));
        return solve(n-1, m-1, a, b, dp);
    } 

 

Rec+Memo+Shifting :
int solve(int i, int j, int a[], int b[], vector<vector<int>> &dp) 
    { 
        if(j==0){
            return 0;
        }
        
        if(i==0){
            return -1e9;
        }
        
        if(dp[i][j]!=-1) return dp[i][j];
      
        int notpick = 0 + solve(i-1, j, a, b, dp);
        int pick = a[i-1]*b[j-1] + solve(i-1, j-1, a, b, dp);
        
        return dp[i][j] = max(notpick, pick);
    }
    
    int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(n+1, vector<int>(m+1, -1));
        return solve(n, m, a, b, dp);
    } 

 

Tabulation :
int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<vector<int>> dp(n+1, vector<int>(m+1, 0));
        
        for(int j=1;j<=m;j++){
            dp[0][j] = -1e9;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m;j++){
                int notpick = 0 + dp[i-1][j];
                int pick = a[i-1]*b[j-1] + dp[i-1][j-1];
                
                dp[i][j] = max(notpick, pick);
            }
        }
        return dp[n][m];
    } 

 

Space Optimization :
int maxDotProduct(int n, int m, int a[], int b[]) 
    { 
        vector<int> prev(m+1, 0), curr(m+1, 0);
        
        for(int j=1;j<=m;j++){
            prev[j] = -1e9;
        }
        
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m;j++){
                int notpick = 0 + prev[j];
                int pick = a[i-1]*b[j-1] + prev[j-1];
                
                curr[j] = max(notpick, pick);
            }
            prev = curr;
        }
        return prev[m];
    } 
