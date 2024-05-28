class Solution { 
  public:
  int solve(int n, int w, vector<int> &cost, vector<int> &dp) {
      
        if(w == 0)  return 0;
        
        if(dp[w] != -1) return dp[w];
        
        int ans = INT_MAX;
        
        for(int i = 1; i <= min(n, w); i++) {
            ans = min(ans, solve(n, w-i, cost, dp) + cost[i-1]);
        }
        
        return dp[w] = ans;
  }
    int minimumCost(int n, int w, vector<int> &cost) {
        // code here
        vector<int> dp(w+1, -1);
        
        
        
        int ans = solve(n, w, cost, dp);
        if(ans == INT_MAX) return -1;
        return  ans;
        
    }
};
