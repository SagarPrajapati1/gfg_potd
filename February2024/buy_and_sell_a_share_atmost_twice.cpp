class Solution
{   
    int solve(int ind, int buy, vector<int> &price, int limit, vector<vector<vector<int>>>& dp)
    {    
        if(ind == price.size()) return 0;
        
        if(limit == 0) return 0;
        
        if(dp[ind][buy][limit] != -1) return dp[ind][buy][limit];
        
        int profit = 0;
        
        if(buy) {
            int canBuy = -price[ind] + solve(ind+1, 0, price, limit, dp);
            int canSkip = 0 + solve(ind+1, 1, price, limit, dp);
            profit = max(canBuy, canSkip);
        }
        else {
            int canSell = price[ind] + solve(ind+1, 1, price, limit-1, dp);
            int canSkip = 0 + solve(ind+1, 0, price, limit, dp);
            profit = max(canSkip, canSell);
        }
        
        return dp[ind][buy][limit] = profit;
    }
    
    
    int solveTab(vector<int>& price) {
            int n = price.size();
            vector<vector<vector<int>>> dp(n+1, vector<vector<int>> (2, vector<int> (4, 0)));
            
            for(int i=n-1; i>=0; i--) {
                for(int allowed=0; allowed<=1; allowed++) {
                    for(int transactions=0; transactions<=2; transactions++) {
                        if(transactions == 0) {
                            dp[i][allowed][transactions] = 0;
                        } else {
                            int profit = 0;
                            if(allowed) {
                                int buy = -price[i] + dp[i+1][false][transactions];
                                int leave = 0 + dp[i+1][allowed][transactions];
                                
                                profit = max(buy, leave);
                            } else {
                                int sell = price[i] + dp[i+1][1][transactions-1];
                                int leave = 0 + dp[i+1][allowed][transactions];
                                
                                profit = max(sell, leave);
                            }
                            
                            dp[i][allowed][transactions] = profit;
                        }
                    }
                }
            }
            
            return dp[0][1][2];
        }
        // SPACE OPTIMISATION
        int spaceOptimised(vector<int>& price) {
            int n = price.size();
            vector<vector<int>> curr(2, vector<int> (3, 0)), next(2, vector<int> (3, 0));
            
            for(int i=n-1; i>=0; i--) {
                for(int allowed=0; allowed<=1; allowed++) {
                    for(int transactions=0; transactions<=2; transactions++) {
                        if(transactions == 0) {
                            curr[allowed][transactions] = 0;
                        } else {
                            int profit = 0;
                            if(allowed) {
                                int buy = -price[i] + next[false][transactions];
                                int leave = 0 + next[allowed][transactions];
                                
                                profit = max(buy, leave);
                            } else {
                                int sell = price[i] + next[1][transactions-1];
                                int leave = 0 + next[allowed][transactions];
                                
                                profit = max(sell, leave);
                            }
                            
                            curr[allowed][transactions] = profit;
                        }
                    }
                }
                next = curr;
            }
            
            return curr[1][2];
        }
    
    
    
    public:
        //User function Template for C++
        
        int maxProfit(vector<int>&price){
            //Write your code here..
            
            vector<vector<vector<int>>> dp(price.size(), vector<vector<int> >(2, vector<int> (3, -1)));
            // return solve(0, 1, price, 2, dp);
            // return solveTab(price);
            
            return spaceOptimised(price);
        }
};
