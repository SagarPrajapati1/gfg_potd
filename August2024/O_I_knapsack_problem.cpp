class Solution {
  public:
    // Function to return max value that can be put in knapsack of capacity W.
    vector<vector<int>> memo;
    int knapsackhelper(int index, int W, vector<int>& wt, vector<int>& val) {
        if (index == 0 ) {
            return 0;
        }

        if (memo[index][W] != -1) {
            return memo[index][W];
        }

        int ans = 0;
        if (wt[index - 1] <= W) {
            ans += val[index - 1] + knapsackhelper(index - 1, W - wt[index - 1], wt, val);
            } 
            ans = max(ans,knapsackhelper(index - 1, W, wt, val));
    

        memo[index][W] = ans;
        return ans;
    }

    int knapSack(int W, vector<int>& wt, vector<int>& val) {
        int n = val.size();
        memo.resize(n + 1, vector<int>(W + 1, -1));
        return knapsackhelper(n, W, wt, val);
    }
};
