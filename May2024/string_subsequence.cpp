class Solution {
    
  public:
  
    // int cnt = 0;
    
    // void findSubsequence(int i, string & s1, string &s2, string& temp) {
    //     if(i >= s1.size()){  
    //         if (temp == s2) cnt++;
     
    //         return;
    //     }
        
    //     // pick the element
    //     temp += s1[i];
    //     findSubsequence(i+1, s1, s2, temp);
    //     temp.pop_back();
        
    //     // pick the element
    //     findSubsequence(i+1, s1, s2, temp);
    // }
    
    int countWays(string s1, string s2) {
        // code here
        // vector<string> sub;
        // string temp = "";
        // findSubsequence(0, s1, s2, temp);
        
        // return cnt;
        int mod=1000000000+7;
        int n = s1.length();
        int m = s2.length();
        if(n<m){
            return 0;
        }
        vector<vector<int>> dp(n+1,vector<int>(m+1, 0));
         for (int i = 0; i <= n; ++i) {
            dp[i][0] = 1;
        }
          for (int i = 1; i <= n; ++i) {
            for (int j = 1; j <= m; ++j) {
                dp[i][j] = dp[i-1][j];
                if (s1[i-1] == s2[j-1]) {
                    dp[i][j] = (dp[i][j] + dp[i-1][j-1]) % mod;
                }
            }
        }
        return dp[n][m];
        
    }
};
