class Solution {
public:
    int dp[100005];
    const int mod = 1e9+7;
    
    int cal(int i, int n) {
        if (i >= n)
            return 1;

        if (dp[i] != -1)
            return dp[i];
            
        int t = cal(i + 2, n) % mod;
        int nt = cal(i + 1, n) % mod;

        return dp[i] = (t + nt) % mod;
    }

    int numberOfConsecutiveOnes(int n) {
        memset(dp, -1, sizeof(dp));

        int num = 1;
        for (int i = 1; i <= n; i++) {
            num = (num * 2) % mod;
        }

        int result = num - cal(0, n);
        if (result < 0) {
            result += mod;
        }
        return result;
    }
};
