class Solution {
  public:
    int maximumProfit(vector<int> &prices) {
         int n=prices.size();
        int b=prices[0];
        int profit=0;
        for(int i=1;i<n;i++){
            if(prices[i]>=b){
                profit=max(profit,prices[i]-b);
            }
            else{
                b=prices[i];
            }
        }
        return profit;
    }
};
