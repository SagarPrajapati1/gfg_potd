class Solution {
  public:
    int minimizeCost(int k, vector<int>& heights) {
        // Code here
        int n = heights.size();
        vector<int> dp(n + 1);
 
        dp[0] = 0;
        dp[1] = abs(heights[0] - heights[1]);
     
        // For first k steps.
        for (int i = 2; i <= min(n, k); i++) {
            int x = INT_MAX;
            for (int j = 0; j < i; j++) {
     
                // Choosing minimum value
                if ((abs(heights[i] - heights[j]) + dp[j])
                    < x) {
                    x = abs(heights[i] - heights[j]) + dp[j];
                }
            }
            dp[i] = x;
        }
     
        // If n > k
        if (k < n) {
            for (int i = k + 1; i < n; i++) {
                int x = INT_MAX;
                for (int j = (i - k); j < i; j++) {
     
                    // Choosing minimum value
                    if ((abs(heights[i] - heights[j]) + dp[j])
                        < x) {
                        x = abs(heights[i] - heights[j])
                            + dp[j];
                    }
                }
                dp[i] = x;
            }
        }
        return dp[n-1];
    }
};
