class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
        // code here
        int n = prices.size();
        int mini = prices[0];
        int profit = 0;
        for(int i = 1 ; i < n; i++){
           profit += max(0, prices[i] - prices[i-1]);
        }
        return profit;
    }
};
