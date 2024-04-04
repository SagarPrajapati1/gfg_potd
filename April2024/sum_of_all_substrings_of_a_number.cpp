class Solution
{
    public:
    //Function to find sum of all possible substrings of the given string.
    long long sumSubstrings(string s){
        
        // your code here
        int mod = 1e9+7;
        int n = s.length();
        vector<long long> dp(n, 0);
        dp[0] = s[0]- '0';
        long long res = dp[0];
        
        for(int i = 1; i < s.length(); i++) {
            dp[i] = ((dp[i-1] * 10) % mod + ((s[i]-'0')*(i+1))%mod)%mod;
            res = (res + dp[i])%mod;
        }
        return res;
    }
};
