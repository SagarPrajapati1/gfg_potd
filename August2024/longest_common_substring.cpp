class Solution {
  public:
    int longestCommonSubstr(string str1, string str2) {
        // your code here
        
        int n = str1.length();
        int m = str2.length();
        
        int dp[n+1][m+1];
         for(int i =0;i<=m;i++){
            dp[0][i] =0;
        }
        for(int i =0;i<=n;i++){
            dp[i][0] =0;
        }
        int res = 0;
        for(int i = 1; i <= n; i++) {
            for(int j = 1; j <= m; j++) {
                dp[i][j] = dp[i-1][j-1];
                if(str1[i-1] == str2[j-1]){
                    dp[i][j] = dp[i-1][j-1]+1;
                    res = max(res, dp[i][j]);
                }
                else dp[i][j] = 0;
            }
        }
        
        return res;
        
    }
};
